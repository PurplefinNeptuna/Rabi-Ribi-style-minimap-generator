#include <bits/stdc++.h>
#include <FreeImage.h>
using namespace std;

#define WIDTH 8
#define HEIGHT 8
#define BPP 24

int cnt;

int stoc(char* s) {
	int a = atoi(s);
	return min(255,max(0,a));
}

int main(int argc, char* argv[]) {
	FreeImage_Initialise();
	FIBITMAP* bitmap = FreeImage_Allocate(WIDTH,HEIGHT,BPP);
	RGBQUAD black;
	RGBQUAD white;

	vector<int> argList;
	for(int i=1; i<min(argc,7); i++) {
		argList.push_back(stoc(argv[i]));
	}

	if(argc>=4) {
		black.rgbRed = argList[0];
		black.rgbGreen = argList[1];
		black.rgbBlue = argList[2];
	} else {
		black.rgbRed = 0;
		black.rgbGreen = 0;
		black.rgbBlue = 0;
	}

	if(argc>=7) {
		white.rgbRed = argList[3];
		white.rgbGreen = argList[4];
		white.rgbBlue = argList[5];
	} else {
		white.rgbRed = 255;
		white.rgbGreen = 255;
		white.rgbBlue = 255;
	}

	char name[8];

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

				for(int k=0; k<16; k++) {
					if(		(((k>>3)&1)==0||(((i>>3)&1)==1&&((i>>0)&1)==1))&&
							(((k>>2)&1)==0||(((i>>3)&1)==1&&((i>>2)&1)==1))&&
							(((k>>1)&1)==0||(((i>>2)&1)==1&&((i>>1)&1)==1))&&
							(((k>>0)&1)==0||(((i>>1)&1)==1&&((i>>0)&1)==1))) {

						FreeImage_SetPixelColor(bitmap,0,0,&black);
						FreeImage_SetPixelColor(bitmap,0,7,&black);
						FreeImage_SetPixelColor(bitmap,7,0,&black);
						FreeImage_SetPixelColor(bitmap,7,7,&black);

						if((k>>3)&1)
							FreeImage_SetPixelColor(bitmap,0,7,&white);
						if((k>>2)&1)
							FreeImage_SetPixelColor(bitmap,7,7,&white);
						if((k>>1)&1)
							FreeImage_SetPixelColor(bitmap,7,0,&white);
						if((k>>0)&1)
							FreeImage_SetPixelColor(bitmap,0,0,&white);



						cnt++;
						//saving image
						snprintf(name, 8, "%01X%01X%01X.png", i, j, k);
						if(FreeImage_Save(FIF_PNG,bitmap,name,0))
							printf("Image %s Saved!\n",name);

					}
				}
			}
		}
	}

	printf("Total image: %d",cnt);
	FreeImage_DeInitialise();
	return 0;
}
