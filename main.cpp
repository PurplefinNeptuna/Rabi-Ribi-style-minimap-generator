#include <bits/stdc++.h>
#include <FreeImage.h>
using namespace std;

#define WIDTH 8
#define HEIGHT 8
#define BPP 24

int main() {
	FreeImage_Initialise();
	FIBITMAP* bitmap = FreeImage_Allocate(WIDTH,HEIGHT,BPP);
	RGBQUAD black;
	RGBQUAD white;
	black.rgbBlue = 0;
	black.rgbGreen = 0;
	black.rgbRed = 0;
	white.rgbBlue = 255;
	white.rgbGreen = 255;
	white.rgbRed = 255;

	char name[7];

	for(int i=0; i<16; i++) {
		for(int j=0; j<16; j++) {
			if((i&j)==0) {
				//set border color
				for(int k=0; k<8; k++) {
					for(int l=0; l<8; l++) {
						if(k==0||k==7||l==0||l==7) {
							FreeImage_SetPixelColor(bitmap,k,l,&black);
						} else {
							FreeImage_SetPixelColor(bitmap,k,l,&white);
						}
					}
				}

				//whiten sides
				if((i>>3)&1) {
					FreeImage_SetPixelColor(bitmap,1,7,&white);
					FreeImage_SetPixelColor(bitmap,2,7,&white);
					FreeImage_SetPixelColor(bitmap,3,7,&white);
					FreeImage_SetPixelColor(bitmap,4,7,&white);
					FreeImage_SetPixelColor(bitmap,5,7,&white);
					FreeImage_SetPixelColor(bitmap,6,7,&white);
				} else if((j>>3)&1) {
					FreeImage_SetPixelColor(bitmap,3,7,&white);
					FreeImage_SetPixelColor(bitmap,4,7,&white);
				}

				if((i>>2)&1) {
					FreeImage_SetPixelColor(bitmap,7,1,&white);
					FreeImage_SetPixelColor(bitmap,7,2,&white);
					FreeImage_SetPixelColor(bitmap,7,3,&white);
					FreeImage_SetPixelColor(bitmap,7,4,&white);
					FreeImage_SetPixelColor(bitmap,7,5,&white);
					FreeImage_SetPixelColor(bitmap,7,6,&white);
				} else if((j>>2)&1) {
					FreeImage_SetPixelColor(bitmap,7,3,&white);
					FreeImage_SetPixelColor(bitmap,7,4,&white);
				}

				if((i>>1)&1) {
					FreeImage_SetPixelColor(bitmap,1,0,&white);
					FreeImage_SetPixelColor(bitmap,2,0,&white);
					FreeImage_SetPixelColor(bitmap,3,0,&white);
					FreeImage_SetPixelColor(bitmap,4,0,&white);
					FreeImage_SetPixelColor(bitmap,5,0,&white);
					FreeImage_SetPixelColor(bitmap,6,0,&white);
				} else if((j>>1)&1) {
					FreeImage_SetPixelColor(bitmap,3,0,&white);
					FreeImage_SetPixelColor(bitmap,4,0,&white);
				}

				if(i&1) {
					FreeImage_SetPixelColor(bitmap,0,1,&white);
					FreeImage_SetPixelColor(bitmap,0,2,&white);
					FreeImage_SetPixelColor(bitmap,0,3,&white);
					FreeImage_SetPixelColor(bitmap,0,4,&white);
					FreeImage_SetPixelColor(bitmap,0,5,&white);
					FreeImage_SetPixelColor(bitmap,0,6,&white);
				} else if(j&1) {
					FreeImage_SetPixelColor(bitmap,0,3,&white);
					FreeImage_SetPixelColor(bitmap,0,4,&white);
				}

				//saving image
				snprintf(name, 7, "%01X%01X.png", i, j);
				if(FreeImage_Save(FIF_PNG,bitmap,name,0))
					printf("Image %s Saved!\n",name);
			}
		}
	}

	FreeImage_DeInitialise();
	return 0;
}
