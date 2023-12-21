#include <U8g2lib.h>      // make sure to add U8g2 library and restart Arduino IDE  
#include <SPI.h>
#include <Wire.h>

#define OLED_SDA  2
#define OLED_SCL 14
#define OLED_RST  4


// macros for color (16 bit)
#define RED 0xF800
#define YELLOW 0xFFE0

// Constants representing movement directions for a game or application
#define DIR_STOP 0   // No movement
#define DIR_UP 1     // Upward movement
#define DIR_DOWN 2   // Downward movement
#define DIR_LEFT 3   // Leftward movement
#define DIR_RIGHT 4  // Rightward movement

// Variables for joystick input tracking
int xValue = 0;   // To store the value of the X-axis
int yValue = 0;   // To store the value of the Y-axis
int xLast = 0;    // Store the previous value of X
int yLast = 0;    // Store the previous value of Y, only print out when changes occur

// Set the initial player starting point
int x = 5; 
int y = 25;

// Wall coordinates making up the map
const int WALL_COORDS[][4] = {
  //  <->   up   <->   down
  //  0     0     0     0
  {0, 0, 110, 0}, // top
  {110, 0, 110, 32}, // right
  {0, 32, 32, 32}, // bottom
  {0, 0, 0, 32}, // left
  // Draw the walls of the maze
  };


U8G2_SSD1306_128X32_UNIVISION_F_SW_I2C u8g2(U8G2_R0, OLED_SCL, OLED_SDA , OLED_RST);


void setup() {
  Serial.begin(115200);
  while (!Serial);
  u8g2.begin();

  mazeWalls(YELLOW);  // Draw the additional yellow walls
  
}
 
void loop() {
  // put your main code here, to run repeatedly:

}


// Function to draw maze walls on the screen
void mazeWalls(uint16_t color) {
  // Set the color before drawing the walls
  u8g2.setDrawColor(color);

  // Draw the walls of the maze
  for (int i = 0; i < sizeof(WALL_COORDS) / sizeof(WALL_COORDS[0]); i++) {
    // Extract coordinates of the current wall
    int x1 = WALL_COORDS[i][0];
    int y1 = WALL_COORDS[i][1];
    int x2 = WALL_COORDS[i][2];
    int y2 = WALL_COORDS[i][3];

    // Draw the line without specifying the color again
    u8g2.drawLine(x1, y1, x2, y2);
  }
}
