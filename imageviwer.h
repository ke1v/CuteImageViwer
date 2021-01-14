#pragma once

#include <QMainWindow>

#include <QLabel>
#include <QImage>
#include <QScrollArea>
#include <QAction>
#include <QFileDialog>
#include <QMenuBar>
#include <QGuiApplication>
#include <QMessageBox>
#include <QDebug>

/*
 *  Planned Features:
 *  - Crop
 *	- Flip
 *  - Filters
 *  - Scale
 */

class ImageViwer : public QMainWindow {
    Q_OBJECT

public:
    ImageViwer(QWidget *parent = nullptr);
    ~ImageViwer();

private:
	void createMenus();
	void updateActions();
	bool saveFile(const QString &fileName);
	void setImage(const QImage &newImage);
	void scaleImage(double factor);

	QImage image;
	QString imagePath;
	QLabel *imageLabel;
	QScrollArea *scrollArea;
	double scaleFactor = 1;

	QAction openAction;
	QAction saveAction;
	QAction saveAsAction;
	QAction quitAction;
	QAction copyAction;
	QAction flipHortizontallyAction;
	QAction flipVerticallyAction;
	QAction zoomInAction;
	QAction zoomOutAction;
	QAction normalSizeAction;
	QAction fitToWindwAction;
	QAction fitToImageAction;

private slots:
	void open();
	void save();
	void saveAs();
	void copy();
	void paste();
	void zoomIn();
	void zoomOut();
	void fitToWindow();
	void fitToImage();
	void normalSize();
	void about();
};
