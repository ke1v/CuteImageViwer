#include "imageviwer.h"

ImageViwer::ImageViwer(QWidget *parent)
	: QMainWindow(parent), imageLabel(new QLabel("Hello")), scrollArea(new QScrollArea) {

	imageLabel->setBackgroundRole(QPalette::Base);
//	imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	imageLabel->setScaledContents(true);

	scrollArea->setBackgroundRole(QPalette::Dark);
	scrollArea->setWidget(imageLabel);
	scrollArea->setVisible(true);
//	scrollArea->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
	setCentralWidget(scrollArea);

	QMenuBar *menu = menuBar();

	QMenu *fileMenu = menu->addMenu("File");
	QMenu *editMenu = menu->addMenu("Edit");
	QMenu *viewMenu = menu->addMenu("View");
	QMenu *helpMenu = menu->addMenu("Help");

	//File Menu
	QAction *openAction = fileMenu->addAction("Open");
	QAction *saveAction = fileMenu->addAction("Save");
	QAction *saveAsAction = fileMenu->addAction("Save As");
	QAction *quitAction = fileMenu->addAction("Quit");

	//Edit Menu
	QAction *copyAction = fileMenu->addAction("Copy");
	QAction *flipHorizontalAction = fileMenu->addAction("Flip Horizontally");
	QAction *flipVerticallyAction = fileMenu->addAction("Flip Vertically");

	//View Menu

	//Help Menu


	connect(openAction, &QAction::triggered, this, &ImageViwer::open);

	menu->show();

//	createActions();
	resize(800, 450);

}

ImageViwer::~ImageViwer() {
	delete imageLabel;
	delete scrollArea;
}


//	Slots
void ImageViwer::open() {
	imagePath = QFileDialog::getOpenFileName(this, "Open Image", "./", tr("Images (*.png *.jpg)"));

	if (!image.load(imagePath)) {
		QMessageBox::critical(this, "Could not open image", "The file " + imagePath + " could not be loaded!");
		return;
	}

	imageLabel->setPixmap(QPixmap::fromImage(image));
	imageLabel->adjustSize();
}

void ImageViwer::saveAs() {

};

void ImageViwer::copy() {

};

void ImageViwer::paste() {

};

void ImageViwer::zoomIn() {

};

void ImageViwer::zoomOut() {

};

void ImageViwer::fitToWindow() {

};

void ImageViwer::fitToImage() {

};

void ImageViwer::normalSize() {

};

void ImageViwer::save() {

}

void ImageViwer::about() {

}

