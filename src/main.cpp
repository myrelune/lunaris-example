extern "C" {
    #include "Lunaris.h"
}

#include <vector>
#include <random>

struct Particle {
    Vec2 center;
    float radius;
    Color color;
    Vec2 velocity;
};

int main() {
    InitWindow(800, 600, "particle");

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<float> distX(0.0f, (float)GetScreenWidth());
    std::uniform_real_distribution<float> distY(0.0f, (float)GetScreenHeight());

    std::uniform_real_distribution<float> distVel(-3.0f, 3.0f);

    std::vector<Particle> particles;
    particles.reserve(1000);

    for (int i = 0; i < 1000; i++) {
        Particle p;

        p.center = {distX(gen), distY(gen)};
        p.radius = 10.0f;

        float vx = 0.0f;
        float vy = 0.0f;
        while (vx == 0.0f) vx = distVel(gen);
        while (vy == 0.0f) vy = distVel(gen);

        p.velocity = {vx, vy};
        particles.push_back(p);
    }

    while (!WindowShouldClose()) {
        BeginDrawing();

        for (auto& p : particles) {
            if (p.center.x > GetScreenWidth() || p.center.x < 0) {
                p.velocity.x *= -1.0f;
            }
            if (p.center.y > GetScreenHeight() || p.center.y < 0) {
                p.velocity.y *= -1.0f;
            }
            p.center.x += p.velocity.x;
            p.center.y += p.velocity.y;

            DrawCircle(p.center, p.radius, RED);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
