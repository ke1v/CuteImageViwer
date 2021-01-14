#include "imageviwer.h"

ImageViwer::ImageViwer(QWidget *parent)
	: QMainWindow(parent), imageLabel(new QLabel("No Image Open")), scrollArea(new QScrollArea) {

	imageLabel->setBackgroundRole(QPalette::Base);
	imageLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
	imageLabel->setScaledContents(true);

	scrollArea->setAlignment(Qt::AlignCenter);
	scrollArea->setBackgroundRole(QPalette::Base);
	scrollArea->setWidgetResizable(true);
	scrollArea->setWidget(imageLabel);
	scrollArea->setVisible(true);
	setCentralWidget(scrollArea);

	createMenus();
	resize(600, 600);
//	adjustSize();
}

ImageViwer::~ImageViwer() {
	delete imageLabel;
	delete scrollArea;
}


void ImageViwer::createMenus() {
	//Grabbing menu pointer
	QMenuBar *menu = menuBar();

	//Main Menu
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

	//Connecting Actions to functions
	connect(openAction, &QAction::triggered, this, &ImageViwer::open);
	connect(saveAction, &QAction::triggered, this, &ImageViwer::save);
	connect(saveAsAction, &QAction::triggered, this, &ImageViwer::saveAs);

	menu->show();
}

//	Slots
void ImageViwer::open() {
	imagePath = QFileDialog::getOpenFileName(this, "Open Image", "./", tr("Images (*.png *.jpg)"));

	if (!image.load(imagePath)) {
		QMessageBox::critical(this, "Could not open image", "The file " + imagePath + " could not be loaded!");
		return;
	}

	imageLabel->setPixmap(QPixmap::fromImage(image));
	//Resizes Label
	imageLabel->adjustSize();
	//Resizes Window
	qDebug() << imageLabel->size();
}

void ImageViwer::save() {
	image.save(imagePath);
}

void ImageViwer::saveAs() {
	imagePath = QFileDialog::getSaveFileName(this, "Save as", "./", tr("Images (*.png *.jpg)"));
	image.save(imagePath);
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

void ImageViwer::about() {

}

