#include <Adafruit_NeoPixel.h>
#include <math.h>

#define PIN 2
#define NUMPIXELS 25

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Pulse settings
float pulsePhase = 0.0;
float pulseSpeed = 0.01;
bool pulseStarted = false;

// Function to get the color from pulse intensity logic
uint32_t getPulseColor(float intensity) {
  int r, g, b;

  if (intensity < 0.5) {
    float t = intensity * 2;
    r = (1 - t) * 50 + t * 0;
    g = (1 - t) * 255 + t * 100;
    b = 255;
  } else {
    float t = (intensity - 0.5) * 2;
    r = t * 180;
    g = 100 + t * (255 - 100);
    b = 255;
  }

  return pixels.Color(r, g, b);
}

void setup() {
  pixels.begin();
  pixels.show();

  // Calculate initial color at intensity 0.5 (the starting point of the pulse)
  uint32_t initialColor = getPulseColor(0.5);

  // --- Smooth Startup Animation ---
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, initialColor);
    pixels.show();
    delay(60);
  }

  // No brightness change – immediate smooth pulse begins
  delay(100);
  pulseStarted = true;
}

void loop() {
  if (pulseStarted) {
    float intensity = (sin(pulsePhase) + 1.0) / 2.0;

    uint32_t pulseColor = getPulseColor(intensity);

    for (int i = 0; i < NUMPIXELS; i++) {
      pixels.setPixelColor(i, pulseColor);
    }
    pixels.show();

    pulsePhase += pulseSpeed;
    if (pulsePhase >= 2 * PI) pulsePhase -= 2 * PI;

    delay(30);
  }
}
