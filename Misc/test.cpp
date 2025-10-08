#include <stdio.h>
#include <unistd.h>
#include <math.h>

void clearScreen() {
    printf("\033[H\033[J");
}

void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

int main() {
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];
    
    while(1) {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        
        for(j = 0; j < 6.28; j += 0.07) {
            for(i = 0; i < 6.28; i += 0.02) {
                float c = sin(i);
                float d = cos(j);
                float e = sin(A);
                float f = sin(j);
                float g = cos(A);
                float h = d + 2;
                float D = 1 / (c * h * e + f * g + 5);
                float l = cos(i);
                float m = cos(B);
                float n = sin(B);
                float t = c * h * g - f * e;
                
                int x = 40 + 30 * D * (l * h * m - t * n);
                int y = 12 + 15 * D * (l * h * n + t * m);
                int o = x + 80 * y;
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = "&"[N > 0 ? 0 : 1];
                }
            }
        }
        
        clearScreen();
        gotoxy(1, 1);
        
        for(k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);
        }
        
        A += 0.04;
        B += 0.02;
        usleep(30000);
    }
    
    return 0;
}
