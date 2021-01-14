#include "imageviwer.h"

#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication ImageViwerApp(argc, argv);
	ImageViwer viewer;
	viewer.show();
	return ImageViwerApp.exec();
}
