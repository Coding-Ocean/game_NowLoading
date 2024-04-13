#include<thread>
#include"libOne.h"

void loadingMsg(bool& stopFlag) {
	float angle = 0;
	rectMode(CENTER);
	angleMode(DEGREES);
	while (!stopFlag) {
		angle += 1;
		clear();
		fill(100, 100, 100);
		rect(width / 2, height / 2, 200, 200, angle);
		fill(255);
		textSize(100);
		text("NowLoding...", width / 2, height / 2);
		present();
	}
}

void load(int& img) {
	bool stopFlag = false;
	std::thread th(loadingMsg, std::ref(stopFlag));

	img = loadImage("schoolGal.jpg");
	std::this_thread::sleep_for(std::chrono::seconds(3));

	stopFlag = true;
	th.join();
}

void gmain(){
	window(1600,900);

	int img;
	load(img);

	while (notQuit)	{
		clear();
		rectMode(CENTER);
		image(img, width / 2, height / 2, 0.0f, 0.85f);
	}
}