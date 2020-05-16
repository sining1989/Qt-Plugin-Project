/*!
 * \file    opencv_panel.cpp
 * \date    2019.10.24
 * \author  zhusizhi
 * \version 1.0.0
 *
 * \brief   OPENCV panel
 *
 */
#include "opencv_panel.h"

namespace general_demo
{
	int interNum = 100;//迭代次数
	int internum1;
	OpenCVPanel::OpenCVPanel(QWidget *parent) :
		QMainWindow(parent)
	{
		ui.setupUi(this);
		
		//m_bIsDrawing = false;
		QTimer *timer = new QTimer(this);//当前时间显示
		connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
		timer->start(1000);
		Mat start = imread("images/start.png");
		img_display(start);
	}

	OpenCVPanel::~OpenCVPanel()
	{

	}

	void OpenCVPanel::resizeEvent(QResizeEvent *event)
	{
		this->resize(this->size());
	}

	void OpenCVPanel::timerUpdate()//显示时间函数
	{
		QDateTime time = QDateTime::currentDateTime();
		QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
		ui.label_time->setText(str);
	}

	//-------------Mat与QImage的转化----------------------//
	QImage OpenCVPanel::cvMat2QImage(const cv::Mat& mat)
	{
		// 8-bits unsigned, NO. OF CHANNELS = 1
		if (mat.type() == CV_8UC1)
		{
			QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
			// Set the color table (used to translate colour indexes to qRgb values)
			image.setColorCount(256);
			for (int i = 0; i < 256; i++)
			{
				image.setColor(i, qRgb(i, i, i));
			}
			// Copy input Mat
			uchar *pSrc = mat.data;
			for (int row = 0; row < mat.rows; row++)
			{
				uchar *pDest = image.scanLine(row);
				memcpy(pDest, pSrc, mat.cols);
				pSrc += mat.step;
			}
			return image;
		}
		// 8-bits unsigned, NO. OF CHANNELS = 3
		else if (mat.type() == CV_8UC3)
		{
			// Copy input Mat
			const uchar *pSrc = (const uchar*)mat.data;
			// Create QImage with same dimensions as input Mat
			QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
			return image.rgbSwapped();
		}
		else if (mat.type() == CV_8UC4)
		{
			qDebug() << "CV_8UC4";
			// Copy input Mat
			const uchar *pSrc = (const uchar*)mat.data;
			// Create QImage with same dimensions as input Mat
			QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
			return image.copy();
		}
		else
		{
			qDebug() << "ERROR: Mat could not be converted to QImage.";
			return QImage();
		}
	}

	Mat OpenCVPanel::QImage2cvMat(QImage image)
	{
		cv::Mat mat;
		qDebug() << image.format();
		switch (image.format())
		{
		case QImage::Format_ARGB32:
		case QImage::Format_RGB32:
		case QImage::Format_ARGB32_Premultiplied:
			mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
			break;
		case QImage::Format_RGB888:
			mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
			cv::cvtColor(mat, mat, CV_BGR2RGB);
			break;
		case QImage::Format_Indexed8:
			mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
			break;
		}
		return mat;
	}

	//-------------显示图片函数----------------------//
	void OpenCVPanel::img_display(Mat image)
	{
		dispimg = cvMat2QImage(image);
		ui.label->clear();
		ui.label->setPixmap(QPixmap::fromImage(dispimg));
		ui.label->resize(ui.label->pixmap()->size());
	}

	void OpenCVPanel::img_display_1(Mat image)
	{
		ui.label_1->setVisible(true);
		dispimg = cvMat2QImage(image);
		ui.label_1->clear();
		ui.label_1->setPixmap(QPixmap::fromImage(dispimg));
		ui.label_1->resize(ui.label_1->pixmap()->size());
	}
	void OpenCVPanel::img_display_2(Mat image)
	{
		ui.label_2->setVisible(true);
		dispimg = cvMat2QImage(image);
		ui.label_2->clear();
		ui.label_2->setPixmap(QPixmap::fromImage(dispimg));
		ui.label_2->resize(ui.label_2->pixmap()->size());
	}

	//--------------暂时隐藏不需要的部件--------------//
	void OpenCVPanel::ui_hide()
	{
		ui.thresh_Slider->setVisible(false);
		ui.label_thresh->setVisible(false);
		ui.thresh_Slider_1->setVisible(false);
		ui.label_thresh_1->setVisible(false);
		ui.comboBox1->setVisible(false);
		ui.comboBox2->setVisible(false);
		ui.label_1->setVisible(false);
		ui.label_2->setVisible(false);
		ui.tip2->setVisible(false);
		ui.tip3->setVisible(false);
		ui.spinBox->setVisible(false);
	}

	//--------------设置滑块的参数--------------//
	void OpenCVPanel::setSlider(int Slider_Min, int Slider_Max, int Slider_Val)
	{
		ui.thresh_Slider->setVisible(true);//显示滑块
		ui.label_thresh->setVisible(true);//显示滑块值
		ui.thresh_Slider->setMinimum(Slider_Min);//设置滑动条控件的最小值
		ui.thresh_Slider->setMaximum(Slider_Max);//设置滑动条控件的最大值
		ui.thresh_Slider->setValue(Slider_Val);//设置滑动条控件的初始值
		ui.thresh_Slider->setPageStep(1);//设置滑动条控件的单步间隔值,可惜只能int
	}

	//--------------设置滑块_1的参数--------------//
	void OpenCVPanel::setSlider_1(int Slider_Min, int Slider_Max, int Slider_Val)
	{
		ui.thresh_Slider_1->setVisible(true);//显示滑块
		ui.label_thresh_1->setVisible(true);//显示滑块值
		ui.thresh_Slider_1->setMinimum(Slider_Min);//设置滑动条控件的最小值
		ui.thresh_Slider_1->setMaximum(Slider_Max);//设置滑动条控件的最大值
		ui.thresh_Slider_1->setValue(Slider_Val);//设置滑动条控件的初始值
		ui.thresh_Slider_1->setPageStep(1);//设置滑动条控件的单步间隔值,可惜只能int
	}

	//----------------------开始----------------------//
	void OpenCVPanel::on_open_image_triggered()//打开图片
	{
		QString filename;
		filename = QFileDialog::getOpenFileName(this, tr("选择图像"), "", tr("Images(*.png *.bmp *.jpg *.tif *.GIF )"));
		QTextCodec *code = QTextCodec::codecForName("gb18030");//为了使用中文路径
		std::string name = code->fromUnicode(filename).data();
		image = cv::imread(name);//读入原始图像矩阵
		image.copyTo(init_img);//把打开的图像保存到全局变量init_img中，用于初始化还原图像
		image.copyTo(rep_img);//把图像保存到全局变量rep_img中，用于撤销操作
		if (filename.isEmpty())
			return;
		else 
			img_display(image);
		//m_pix = QPixmap(image.cols, image.rows);
		//m_pix.fill(Qt::white);
		ui_hide();//隐藏不需要的部件
		thresh = 1;
		thresh_1 = 1;
		MORPH = 0;
		//以下为相对于图片的坐标
		x = 0;
		y = 0;
		x1 = ui.label->width();
		y1 = ui.label->height();
		ui.tip1->setText(tr("原始图."));
		statusBar()->showMessage(tr("已正确打开图片."));
	}

	void OpenCVPanel::on_print_image_triggered()//打印图片
	{
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		QPrinter printer;
		QPrintDialog printDialog(&printer, this);
		if (printDialog.exec())//判断是否点击了”打印”
		{
			QPainter painter(&printer);
			QRect rect = painter.viewport();
			QSize size = dispimg.size();
			size.scale(rect.size(), Qt::KeepAspectRatio);//使图像铺满整个页面
			painter.setViewport(rect.x(), rect.y(), size.width(), size.height());
			painter.setWindow(dispimg.rect());
			painter.drawImage(0, 0, dispimg);
		}
		statusBar()->showMessage(tr("已正确打印图像."));
	}

	void OpenCVPanel::on_save_image_triggered()//保存图片
	{
		QString filename;
		filename = QFileDialog::getSaveFileName(this, tr("保存图像"), "", tr("Images(*.png)"));
		QTextCodec *code = QTextCodec::codecForName("gb18030");//为了使用中文路径
		std::string name = code->fromUnicode(filename).data();
		if (filename.isEmpty()) return;
		else cv::imwrite(name, image);//保存image到指定文件夹下，是BGR格式
		statusBar()->showMessage(tr("已正确保存图像."));
	}

	void OpenCVPanel::on_exit_image_triggered()//退出系统
	{
		if (!(QMessageBox::information(this, tr("提示"), tr("确定退出系统?"), tr("Yes"), tr("No"))))
		{
			this->close();
		}
	}

	void OpenCVPanel::on_camera_image_triggered()//打开摄像头
	{
		VideoCapture capture(0);
		while (1)  //循环显示每一帧
		{
			Mat frame;  //定义一个Mat变量，用于存储每一帧的图像
			if (!capture.isOpened())return;
			capture >> frame;  //读取当前帧
			imshow("Camera", frame);  //显示当前帧
			char c = waitKey(30);  //延时30ms
			if (c == 13)//按下Enter保存图像
			{
				frame.copyTo(image);
				img_display(image);
				break;
			}
			if (c == 27)break;//按下ESC退出
		}
		//cvDestroyWindow("Camera");
		statusBar()->showMessage(tr("已正确打开摄像头，按Enter键截屏保存."));
	}

	//-------------工具条操作---------------------//
	void OpenCVPanel::on_repeal_image_triggered()//撤销
	{
		img_display(rep_img);
		rep_img.copyTo(image);
		statusBar()->showMessage(tr("已撤销上一次图像操作."));
	}

	void OpenCVPanel::on_init_image_triggered()//还原
	{
		img_display(init_img);
		ui.tip1->setText(tr("原始图."));
		init_img.copyTo(image);
		ui_hide();
		flag = 0;
		thresh = 1;
		thresh_1 = 1;
		MORPH = 0;
		interNum = 100;
		ui.comboBox2->setCurrentIndex(0);
		ui.spinBox->setValue(50);
		x = 0;
		y = 0;
		x1 = ui.label->width();
		y1 = ui.label->height();
		statusBar()->showMessage(tr("已恢复原始图像."));
		ui.tip1->setText(tr("原始图."));
	}

	void OpenCVPanel::on_OK_image_triggered()//确定
	{
		flag = 255;
		dst_image.copyTo(image);
		ui_hide();
		statusBar()->showMessage(tr("已确认本操作."));
	}

	void OpenCVPanel::on_print_image_action_triggered()//打印
	{
		on_print_image_triggered();
	}

	void OpenCVPanel::on_open_action_triggered()//打开
	{
		on_open_image_triggered();
		ui_hide();
	}

	void OpenCVPanel::on_save_action_triggered()//保存
	{
		on_save_image_triggered();
	}

	void OpenCVPanel::on_camera_action_triggered()//摄像头
	{
		on_camera_image_triggered();
	}

	void OpenCVPanel::on_zoom_in_triggered()//放大
	{
		QImage dst;
		QImage src;
		image.copyTo(rep_img);
		src = cvMat2QImage(image);
		if (src.isNull()) return;
		QMatrix matrix;
		matrix.scale(1.5, 1.5);
		dst = src.transformed(matrix);
		Mat dst1 = QImage2cvMat(dst);
		img_display(dst1);
		dst1.copyTo(image);
		statusBar()->showMessage(tr("每次点击放大1.5倍."));
	}

	void OpenCVPanel::on_zoom_out_triggered()//缩小
	{
		QImage dst;
		QImage src;
		image.copyTo(rep_img);
		src = cvMat2QImage(image);
		if (src.isNull()) return;
		QMatrix matrix;
		matrix.scale(0.66, 0.66);
		dst = src.transformed(matrix);
		Mat dst1 = QImage2cvMat(dst);
		img_display(dst1);
		dst1.copyTo(image);
		statusBar()->showMessage(tr("每次点击缩小1.5倍."));
	}

	void OpenCVPanel::on_ROI_action_triggered()//设置ROI
	{
		flag = 11;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		statusBar()->showMessage(tr("请拖动鼠标选择一个矩形区域."));
	}

	//-------------鼠标事件---------------------//
	void OpenCVPanel::mousePressEvent(QMouseEvent*event)//按下
	{
		if (event->button() == Qt::LeftButton)//鼠标左键按下
		{
			//m_previousPoint = event->pos();
			//m_bIsDrawing = true;
			x = event->x() - (ui.label->x());
			y = event->y() - (ui.label->y()) - 55;//减去menubar+toobar的高度
			if (flag == 11)//ROI
			{
				statusBar()->showMessage(tr("鼠标相对控件坐标:(") + QString::number(x) + tr(",") + QString::number(y) + tr(")"));
			}
		}
	}

	void OpenCVPanel::mouseMoveEvent(QMouseEvent *event)//移动
	{
		if (event->buttons()&Qt::LeftButton)//鼠标左键按下的同时移动鼠标
		{
			//m_currentPoint = event->pos();
			//update();
			if (flag == 11 | flag == 21)//只在ROI和Grabcut时用
			{
				QPainter paint;
				QPixmap pix;
				x1 = event->x() - (ui.label->x());
				y1 = event->y() - (ui.label->y()) - 55;
				paint.setPen(QColor(Qt::green)); //设定画笔颜色
				paint.setBrush(QColor(Qt::red)); //设定填充颜色
												 // paint.drawRect(QRect(70,70,80,80));
				paint.drawRect(QRect(x, y, x1, y1));
			}
		}
	}

	void OpenCVPanel::mouseReleaseEvent(QMouseEvent *event)//释放
	{
		if (event->button() == Qt::LeftButton)//鼠标左键释放
		{
			//m_currentPoint = event->pos();
			//m_bIsDrawing = false;
			//update();
			if (flag == 11)//只在ROI时用
			{
				if (x >= 0 && y >= 0 && x1 <= ui.label->width() && y1 <= ui.label->height())
				{
					Mat dst, src;
					image.copyTo(rep_img);
					image.copyTo(src);
					cv::Rect rect(x, y, x1 - x, y1 - y);
					src(rect).copyTo(dst);
					img_display(dst);
					dst.copyTo(image);
					ui.tip1->setText(tr("ROI图."));
					statusBar()->showMessage(tr("已获得ROI图像."));
					flag = 0;
					x = 0;
					y = 0;
					x1 = ui.label->width();
					y1 = ui.label->height();
				}
			}
			if (flag == 21)//只在Grabcut时用
			{
				if (x >= 0 && y >= 0 && x1 <= ui.label->width() && y1 <= ui.label->height())
				{
					Mat dst, src, mask;
					image.copyTo(rep_img);
					image.copyTo(src);
					dst = Mat(src.size(), CV_8UC1, cv::Scalar(cv::GC_BGD));//掩模图像必须是8UC1
					if (src.channels() == 1) cvtColor(src, src, CV_GRAY2RGB);//输入图像必须是8UC3
					src.convertTo(src, CV_8UC3);
					cv::Rect rectangle(x, y, x1 - x, y1 - y);// 矩形外的像素是背景
					cv::Mat result;
					//两个临时矩阵变量，作为算法的中间变量使用，不用care
					cv::Mat bgModel, fgModel;
					// GrabCut 分段
					cv::grabCut(src,    //输入图像
						result,   //分段结果
						rectangle,// 包含前景的矩形
						bgModel, fgModel, // 前景、背景
						1,        // 迭代次数
						cv::GC_INIT_WITH_RECT); // 用矩形
												// 得到可能是前景的像素
												//比较函数保留值为GC_PR_FGD的像素
					cv::compare(result, cv::GC_PR_FGD, result, cv::CMP_EQ);
					// 产生输出图像
					cv::Mat foreground(src.size(), CV_8UC3, cv::Scalar(255, 255, 255));
					//背景值为 GC_BGD=0，作为掩码
					image.copyTo(foreground, result);
					img_display(foreground);
					foreground.copyTo(image);
					ui.tip1->setText(tr("用GrabCut算法分割后的图."));
					statusBar()->showMessage(tr("已对图像用GrabCut算法分割."));
				}
			}
		}
	}

	//void OpenCVPanel::paintEvent(QPaintEvent *event)
	//{
	//	int x, y, w, h;
	//	x = m_previousPoint.x();
	//	y = m_previousPoint.y();
	//	w = m_currentPoint.x() - x;
	//	h = m_currentPoint.y() - y;
	//	QPainter painter(this);
	//	if (m_bIsDrawing)
	//	{
	//		m_tempPix = m_pix;
	//		QPainter pp(&m_tempPix);
	//		pp.drawRect(x, y, w, h);
	//		painter.drawPixmap(0, 0, m_tempPix);
	//	}
	//	else
	//	{
	//		QPainter pp(&m_pix);
	//		pp.drawRect(x, y, w, h);
	//		painter.drawPixmap(0, 0, m_pix);
	//	}
	//}

	//-------------图像增强：灰度化---------------------//
	void OpenCVPanel::on_togray_triggered()
	{
		Mat dst, src;
		image.copyTo(rep_img);//处理前图像保存到全局变量rep_img中，用于撤销操作
		image.copyTo(src);//把原图像保存到局部变量src中进行操作
		if (!src.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		dst.create(src.size(), src.type()); // 创建与src同类型和大小的矩阵(dst)
		if (src.channels() == 1) src.copyTo(dst);
		else cvtColor(src, dst, CV_BGR2GRAY); //转换为灰度图
		img_display(dst);
		dst.copyTo(image);//把处理后的图像更新全局变量image中，用于再处理
		ui.tip1->setText(tr("灰度图."));
		statusBar()->showMessage(tr("已对图像灰度化."));
	}

	//-------------图像增强：二值化---------------------//
	void OpenCVPanel::on_tobinary_before_triggered()
	{
		flag = 10;
		Mat dst, src;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		image.copyTo(rep_img);
		image.copyTo(src);
		dst.create(src.size(), src.type());
		if (src.channels() == 3) { cvtColor(src, src, CV_BGR2GRAY); } //转换为灰度图
		threshold(src, dst, thresh, 255, CV_THRESH_BINARY);  //二值化
		img_display(dst);
		if (thresh == 1)thresh = 128;//thresh初始化
		setSlider(0, 255, thresh);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("二值图."));
		statusBar()->showMessage(tr("已对图像二值化."));
	}

	//-------------图像增强：对比度和亮度---------------------//
	void OpenCVPanel::on_contrast_image_triggered()
	{
		flag = 7;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		int beta = thresh_1;//亮度
		float alpha = thresh * 3 / 255;//对比度0-3倍
		Mat dst, src;
		image.copyTo(rep_img);
		image.copyTo(src);
		dst.create(src.size(), src.type());
		if (src.channels() == 3) //BGR图像
		{
			for (int y = 0; y < src.rows; y++)
			{
				for (int x = 0; x < src.cols; x++)
				{
					for (int c = 0; c < 3; c++)
					{
						dst.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha*(src.at<Vec3b>(y, x)[c] + beta));
					}
				}
			}
		}
		else //不是BGR图像
		{
			for (int y = 0; y < src.rows; y++)
			{
				for (int x = 0; x < src.cols; x++)
				{
					dst.at<uchar>(y, x) = saturate_cast<uchar>(alpha*(src.at<uchar>(y, x)) + beta);
				}
			}
		}
		img_display(dst);
		if (thresh == 1)thresh = 60;//thresh初始化
		setSlider(0, 255, thresh);
		if (thresh_1 == 1)thresh_1 = 60;//thresh初始化
		setSlider_1(0, 255, thresh_1);
		dst.copyTo(dst_image);//ok键按下时把dstimage保存到image中，便于接下来再处理
		ui.tip1->setText(tr("处理后图"));
		statusBar()->showMessage(tr("已进行亮度和对比度的调整."));
	}

	//-------------图像增强：直方图均衡化---------------------//
	void OpenCVPanel::on_histogram_equalization_triggered()
	{
		Mat dst, src;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		image.copyTo(rep_img);
		image.copyTo(src);
		if (src.channels() == 1)
			src.copyTo(dst);
		else
			cvtColor(src, dst, CV_BGR2GRAY); //转换为灰度图
		equalizeHist(src, dst);
		img_display(dst);
		dst.copyTo(image);
		ui.tip1->setText(tr("直方图均衡化后的图."));
		statusBar()->showMessage(tr("已对图像进行直方图均衡化."));
	}

	//-------------设置ROI区域---------------------//
	void OpenCVPanel::on_action_ROI_triggered()
	{
		on_ROI_action_triggered();
	}

	//-------------图像形态学操作---------------------//
	void OpenCVPanel::on_dilate_image_triggered()//膨胀
	{
		flag = 22;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat dst, src;
		image.copyTo(rep_img);
		image.copyTo(src);
		Mat element = getStructuringElement(MORPH, Size(thresh, thresh));
		morphologyEx(src, dst, MORPH_DILATE, element, Point(-1, -1), thresh_1);//膨胀
		img_display(dst);
		setSlider(1, 15, thresh);
		setSlider_1(1, 5, thresh_1);
		ui.comboBox1->setVisible(true);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("膨胀后图"));
		statusBar()->showMessage(tr("已对图像进行膨胀."));
	}

	void OpenCVPanel::on_erode_image_triggered()//腐蚀
	{
		flag = 1;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat dst, src;
		image.copyTo(rep_img);
		image.copyTo(src);
		Mat element = getStructuringElement(MORPH, Size(thresh, thresh));
		morphologyEx(src, dst, MORPH_ERODE, element, Point(-1, -1), thresh_1);//腐蚀
		img_display(dst);
		setSlider(1, 15, thresh);
		setSlider_1(1, 5, thresh_1);
		ui.comboBox1->setVisible(true);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("腐蚀后图"));
		statusBar()->showMessage(tr("已对图像进行腐蚀."));
	}

	void OpenCVPanel::on_opening_image_triggered()//开运算
	{
		flag = 2;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat dst, src;
		image.copyTo(rep_img);
		image.copyTo(src);
		Mat element = getStructuringElement(MORPH, Size(thresh, thresh));
		morphologyEx(src, dst, MORPH_OPEN, element, Point(-1, -1), thresh_1);//开运算
		img_display(dst);
		setSlider(1, 15, thresh);
		setSlider_1(1, 5, thresh_1);
		ui.comboBox1->setVisible(true);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("开运算后的图."));
		statusBar()->showMessage(tr("已对图像进行开运算."));
	}

	void OpenCVPanel::on_closing_image_triggered()//闭运算
	{
		flag = 3;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat dst, src;
		image.copyTo(rep_img);
		image.copyTo(src);
		Mat element = getStructuringElement(MORPH, Size(thresh, thresh));
		morphologyEx(src, dst, MORPH_CLOSE, element, Point(-1, -1), thresh_1);//闭运算
		img_display(dst);
		setSlider(1, 15, thresh);
		setSlider_1(1, 5, thresh_1);
		ui.comboBox1->setVisible(true);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("闭运算后的图"));
		statusBar()->showMessage(tr("已对图像进行闭运算."));
	}

	void OpenCVPanel::on_gradient_image_triggered()//梯度
	{
		flag = 4;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat dst, src;
		image.copyTo(rep_img);
		image.copyTo(src);
		Mat element = getStructuringElement(MORPH, Size(thresh, thresh));
		morphologyEx(src, dst, MORPH_GRADIENT, element, Point(-1, -1), thresh_1);//梯度
		img_display(dst);
		setSlider(1, 15, thresh);
		setSlider_1(1, 5, thresh_1);
		ui.comboBox1->setVisible(true);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("梯度化图"));
		statusBar()->showMessage(tr("已对图像进行梯度化."));
	}

	void OpenCVPanel::on_tophat_image_triggered()//顶帽
	{
		flag = 5;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat dst, src;
		image.copyTo(rep_img);
		image.copyTo(src);
		Mat element = getStructuringElement(MORPH, Size(thresh, thresh));
		morphologyEx(src, dst, MORPH_TOPHAT, element, Point(-1, -1), thresh_1);//顶帽
		img_display(dst);
		setSlider(1, 15, thresh);
		setSlider_1(1, 5, thresh_1);
		ui.comboBox1->setVisible(true);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("顶帽处理后图"));
		statusBar()->showMessage(tr("已对图像进行顶帽处理."));
	}

	void OpenCVPanel::on_blackhat_image_triggered()//黑帽
	{
		flag = 6;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat dst, src;
		image.copyTo(rep_img);
		image.copyTo(src);
		Mat element = getStructuringElement(MORPH, Size(thresh, thresh));
		morphologyEx(src, dst, MORPH_BLACKHAT, element, Point(-1, -1), thresh_1);//黑帽
		img_display(dst);
		setSlider(1, 15, thresh);
		setSlider_1(1, 5, thresh_1);
		ui.comboBox1->setVisible(true);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("黑帽处理后的图."));
		statusBar()->showMessage(tr("已对图像进行黑帽处理."));
	}

	//----------------------孔洞填充----------------------//
	void OpenCVPanel::on_hole_fill_triggered()
	{
		flag = 8;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat src;
		image.copyTo(rep_img);
		image.copyTo(src);
		Mat dst = Mat::zeros(src.size(), CV_8UC1);
		if (src.channels() != 1)
			cvtColor(src, src, CV_BGR2GRAY); //src必须为一个2值单通道图像
		src.convertTo(src, CV_8UC1);
		RemoveSmallRegion(src, dst, thresh, 0, 0);
		img_display(dst);
		if (thresh == 1)
			thresh = 100;//thresh初始化
		setSlider(0, 500, thresh);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("孔洞填充后的图."));
		statusBar()->showMessage(tr("已对图像进行孔洞填充."));
	}

	//---------------------去除小面积区域----------------------//
	void OpenCVPanel::on_deduct_small_area_triggered()
	{
		flag = 9;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat src;
		image.copyTo(rep_img);
		image.copyTo(src);
		Mat dst = Mat::zeros(src.size(), CV_8UC1);
		if (src.channels() != 1)
			cvtColor(src, src, CV_BGR2GRAY); //src必须为一个2值单通道图像
		src.convertTo(src, CV_8UC1);
		RemoveSmallRegion(src, dst, thresh, 1, 1);
		img_display(dst);
		if (thresh == 1)thresh = 200;//thresh初始化
		setSlider(0, 1500, thresh);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("去除设定面积区域后的图."));
		statusBar()->showMessage(tr("已对图像去除设定面积区域."));
	}

	//CheckMode: 0代表去除黑区域，1代表去除白区域; NeihborMode：0代表4邻域，1代表8邻域;记录每个像素点检验状态的标签，0代表未检查，1代表正在检查,2代表检查不合格（需要反转颜色），3代表检查合格或不需检查
	void OpenCVPanel::RemoveSmallRegion(Mat& Src, Mat& Dst, int AreaLimit, int CheckMode, int NeihborMode)
	{
		int RemoveCount = 0;       //记录除去的个数
		Mat Pointlabel = Mat::zeros(Src.size(), CV_8UC1);
		if (CheckMode == 1)//去除小区域
		{
			for (int i = 0; i < Src.rows; ++i)
			{
				uchar* iData = Src.ptr<uchar>(i);
				uchar* iLabel = Pointlabel.ptr<uchar>(i);
				for (int j = 0; j < Src.cols; ++j)
				{
					if (iData[j] < 10)
					{
						iLabel[j] = 3;
					}
				}
			}
		}

		else//去除孔洞
		{
			for (int i = 0; i < Src.rows; ++i)
			{
				uchar* iData = Src.ptr<uchar>(i);
				uchar* iLabel = Pointlabel.ptr<uchar>(i);
				for (int j = 0; j < Src.cols; ++j)
				{
					if (iData[j] > 10)
					{
						iLabel[j] = 3;
					}
				}
			}
		}
		vector<Point2i> NeihborPos;  //记录邻域点位置
		NeihborPos.push_back(Point2i(-1, 0));
		NeihborPos.push_back(Point2i(1, 0));
		NeihborPos.push_back(Point2i(0, -1));
		NeihborPos.push_back(Point2i(0, 1));
		if (NeihborMode == 1)
		{
			NeihborPos.push_back(Point2i(-1, -1));
			NeihborPos.push_back(Point2i(-1, 1));
			NeihborPos.push_back(Point2i(1, -1));
			NeihborPos.push_back(Point2i(1, 1));
		}

		int NeihborCount = 4 + 4 * NeihborMode;
		int CurrX = 0, CurrY = 0;
		//开始检测
		for (int i = 0; i < Src.rows; ++i)
		{
			uchar* iLabel = Pointlabel.ptr<uchar>(i);
			for (int j = 0; j < Src.cols; ++j)
			{
				if (iLabel[j] == 0)
				{
					//********开始该点处的检查**********
					vector<Point2i> GrowBuffer;   //堆栈，用于存储生长点
					GrowBuffer.push_back(Point2i(j, i));
					Pointlabel.at<uchar>(i, j) = 1;
					int CheckResult = 0;   //用于判断结果（是否超出大小），0为未超出，1为超出
					for (int z = 0; z<GrowBuffer.size(); z++)
					{
						for (int q = 0; q<NeihborCount; q++)
						{
							CurrX = GrowBuffer.at(z).x + NeihborPos.at(q).x;
							CurrY = GrowBuffer.at(z).y + NeihborPos.at(q).y;
							if (CurrX >= 0 && CurrX<Src.cols&&CurrY >= 0 && CurrY<Src.rows)
							{
								if (Pointlabel.at<uchar>(CurrY, CurrX) == 0)
								{
									GrowBuffer.push_back(Point2i(CurrX, CurrY));  //邻域点加入buffer
									Pointlabel.at<uchar>(CurrY, CurrX) = 1; //更新邻域点的检查标签，避免重复检查
								}
							}
						}
					}
					if (GrowBuffer.size()>AreaLimit) CheckResult = 2;//判断结果（是否超出限定的大小），1为未超出，2为超出
					else
					{
						CheckResult = 1;
						RemoveCount++;
					}
					for (int z = 0; z<GrowBuffer.size(); z++)                         //更新Label记录
					{
						CurrX = GrowBuffer.at(z).x;
						CurrY = GrowBuffer.at(z).y;
						Pointlabel.at<uchar>(CurrY, CurrX) += CheckResult;
					}
					//********结束该点处的检查**********
				}
			}
		}
		CheckMode = 255 * (1 - CheckMode);
		//开始反转面积过小的区域
		for (int i = 0; i < Src.rows; ++i)
		{
			uchar* iData = Src.ptr<uchar>(i);
			uchar* iDstData = Dst.ptr<uchar>(i);
			uchar* iLabel = Pointlabel.ptr<uchar>(i);
			for (int j = 0; j < Src.cols; ++j)
			{
				if (iLabel[j] == 2)
				{
					iDstData[j] = CheckMode;
				}
				else if (iLabel[j] == 3)
				{
					iDstData[j] = iData[j];
				}
			}
		}
	}

	//----------------------设为种子-------------------//
	void OpenCVPanel::on_seed_action_triggered()
	{
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat src, seed;
		image.copyTo(rep_img);
		image.copyTo(seed1);
		QMessageBox::StandardButton res = QMessageBox::information(this, tr("提示"), tr("种子(标记)图像设定完毕，请选择需要处理的原始图像."), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		if (res == QMessageBox::Yes)
		{
			QString filename;
			filename = QFileDialog::getOpenFileName(this, tr("选择需要处理的图像."), "", tr("Images(*.png *.bmp *.jpg *.tif *.GIF )"));
			QTextCodec *code = QTextCodec::codecForName("gb18030");
			std::string name = code->fromUnicode(filename).data();
			src = cv::imread(name);
			if (filename.isEmpty())
				return;
			else
			{
				img_display(src);
				img_display_1(seed1);
				ui.tip2->setVisible(true);
				ui.tip2->setText(tr("种子图."));
				ui.tip1->setText(tr("原始图."));
				src.copyTo(image1);//保存为image1
			}
		}
		flag = 100;//种子设定完毕的标志
		statusBar()->showMessage(tr("种子设定完毕的标志."));
	}

	//----------------------重构函数--------------------//
	Mat OpenCVPanel::morphReconstruct(Mat src, Mat seed1)
	{
		/*功能：实现形态学重构
		src是原图像，seed1是标记图像，dst是重构后的输出图*/
		Mat se = getStructuringElement(MORPH_RECT, Size(3, 3));
		Mat tmp1(src.size(), CV_8U), tmp2(src.size(), CV_8U);
		Mat dst;
		min(src, seed1, dst);
		do
		{
			dst.copyTo(tmp1);
			dilate(dst, seed1, se);
			min(src, seed1, dst);
			tmp2 = abs(tmp1 - dst);
		} while (sum(tmp2).val[0] != 0);
		return dst;
	}
	//----------------------形态学重构---------------------//
	void OpenCVPanel::on_Reconstruct_action_triggered()
	{
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		if (flag == 100)
		{
			Mat src, dst;
			image1.copyTo(src);
			dst = morphReconstruct(src, seed1);
			img_display_2(dst);
			flag = 0;
			dst.copyTo(image);
			ui.tip3->setVisible(true);
			ui.tip3->setText(tr("重构后的图."));
			statusBar()->showMessage(tr("已对图像进行重构."));
		}
		else
			QMessageBox::warning(this, tr("Warning"), tr("请先设定种子图像."));
	}

	//----------------------轮廓的提取与描述----------------------//
	void OpenCVPanel::on_contours_describe_triggered()
	{
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat src, dst;
		image.copyTo(rep_img);
		image.copyTo(src);
		if (src.channels() != 1) cvtColor(src, src, CV_BGR2GRAY); //转换为灰度图,src必须为一个2值单通道图像
		dst = Mat::zeros(image.size(), CV_8UC1);//初始化dst单通道图像
		blur(src, src, Size(3, 3));
		Canny(src, src, 128, 128 * 2, 3);
		vector<vector<Point> >contours;
		findContours(src, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);
		//qDebug("%d", contours.size());
		drawContours(dst, contours, -1, Scalar(255), 2);//-1表示所有的轮廓都画
		img_display(dst);
		ui.tip1->setText(tr("轮廓图."));
		statusBar()->showMessage(tr("已对图像进行轮廓的提取."));

		//把这些轮廓转换为可以利用的特征，也就是涉及到轮廓的描述问题，这时就有多种方法可以选择，比如矢量化为多边形、矩形、椭圆等。
		ui.comboBox2->setVisible(true);
		ui.comboBox2->setItemText(0, tr("请选择描述方法."));
		ui.comboBox2->setItemText(1, tr("圆形"));
		ui.comboBox2->setItemText(2, tr("矩形"));
		ui.comboBox2->setItemText(3, tr("多边形."));
		ui.comboBox2->setItemText(4, tr("凸多边形"));
		if (ui.comboBox2->currentIndex() == 0) return;
		if (ui.comboBox2->currentIndex() == 1)
		{
			vector<Point2f>center(contours.size());
			vector<float>radius(contours.size());
			for (unsigned int i = 0; i < contours.size(); i++)
			{
				minEnclosingCircle(contours[i], center[i], radius[i]);
				circle(dst, center[i], static_cast<int>(radius[i]), Scalar(255), 2);
			}
			img_display(dst);
			statusBar()->showMessage(tr("用圆形对图像进行轮廓的描述."));
		}
		if (ui.comboBox2->currentIndex() == 2)
		{
			vector<Rect> boundRect(contours.size());
			for (unsigned int i = 0; i < contours.size(); i++)
			{
				boundRect[i] = boundingRect(Mat(contours[i]));
				rectangle(dst, boundRect[i].tl(), boundRect[i].br(), Scalar(255), 2);
			}
			img_display(dst);
			statusBar()->showMessage(tr("用矩形对图像进行轮廓的描述."));
		}
		if (ui.comboBox2->currentIndex() == 3)
		{
			vector<Point> poly;
			for (int i = 0; i < contours.size(); i++)
			{
				approxPolyDP(Mat(contours[i]), poly, 5, true);
				vector<Point>::const_iterator itp = poly.begin();
				while (itp != (poly.end() - 1))
				{
					line(dst, *itp, *(itp + 1), Scalar(255), 2);
					++itp;
				}
			}
			img_display(dst);
			statusBar()->showMessage(tr("用多边形对图像进行轮廓的描述."));
		}
		if (ui.comboBox2->currentIndex() == 4)
		{
			vector<Point> hull;
			for (int i = 0; i < contours.size(); i++)
			{
				convexHull(Mat(contours[i]), hull);
				vector<Point>::const_iterator ith = hull.begin();
				while (ith != (hull.end() - 1))
				{
					line(dst, *ith, *(ith + 1), Scalar(255), 2);
					++ith;
				}
				line(dst, *ith, *(hull.begin()), Scalar(255), 2);
			}
			img_display(dst);
			statusBar()->showMessage(tr("用凸多边形对图像进行轮廓的描述."));
		}
		dst.copyTo(dst_image);
		//我们可以进一步计算每一个连通区域的其他属性，比如：重心、中心矩等特征，
		//可以尝试：minAreaRect：计算一个最小面积的外接矩形，contourArea可以计算轮廓内连通区域的面 积；
		//pointPolygenTest可以用来判断一个点是否在一个多边形内。mathShapes可以比较两个形状的相似性。
	}

	//----------------------UI小部件的设置----------------------//
	void OpenCVPanel::on_thresh_Slider_valueChanged(int value)//thresh滑块的设置
	{
		thresh = ui.thresh_Slider->value();
		QString str;
		switch (flag) {

		case 22:
			str = "掩模大小.";
			str.append(QString::number(thresh));
			on_dilate_image_triggered();
			break;
		case 1:
			str = "掩模大小.";
			str.append(QString::number(thresh));
			on_erode_image_triggered();
			break;
		case 2:
			str = "掩模大小.";
			str.append(QString::number(thresh));
			on_opening_image_triggered();
			break;
		case 3:
			str = "掩模大小.";
			str.append(QString::number(thresh));
			on_closing_image_triggered();
			break;
		case 4:
			str = "掩模大小.";
			str.append(QString::number(thresh));
			on_gradient_image_triggered();
			break;
		case 5:
			str = "掩模大小.";
			str.append(QString::number(thresh));
			on_tophat_image_triggered();
			break;
		case 6:
			str = "掩模大小.";
			str.append(QString::number(thresh));
			on_blackhat_image_triggered();
			break;
		case 7:
			str = "对比系数.";
			str.append(QString::number(thresh * 3 / 100));
			on_contrast_image_triggered();
			break;
		case 8:
			str = "孔洞面积临界值.";
			str.append(QString::number(thresh));
			on_hole_fill_triggered();
			break;
		case 9:
			str = "小面积区域临界值.";
			str.append(QString::number(thresh));
			on_deduct_small_area_triggered();
			break;
		case 10:
			str = "阈值.";
			str.append(QString::number(thresh));
			on_tobinary_before_triggered();
			break;
		case 11:
			str = "滞后性阈值.";
			str.append(QString::number(thresh));
			on_actionCanny_triggered();
			break;
		case 12:
			str = "Sobel核的大小.";
			if (thresh == 2 | thresh == 4 | thresh == 6) return;
			else
			{
				on_actionSobel_triggered();
				str.append(QString::number(2 * thresh + 1));
			}
			break;
		case 13:
			str = "Laplacian核的大小.";
			if (thresh == 2 | thresh == 4 | thresh == 6) return;
			else
			{
				on_actionLaplacian_triggered();
				str.append(QString::number(2 * thresh + 1));
			}
			break;
		case 14:
			str = "方框滤波内核的大小.";
			str.append(QString::number(thresh));
			on_BoxFilter_triggered();
			break;
		case 15:
			str = "均值滤波内核的大小.";
			str.append(QString::number(thresh));
			on_MeanBlur_triggered();
			break;
		case 16:
			str = "高斯滤波内核的大小.";
			if (thresh == 2 | thresh == 4 | thresh == 6) return;
			else
			{
				on_GaussianBlur_triggered();
				str.append(QString::number(2 * thresh + 1));
			}
			break;
		case 17:
			str = "中值滤波内核的大小.";
			if (thresh == 2 | thresh == 4 | thresh == 6) return;
			else
			{
				on_MedianBlur_triggered();
				str.append(QString::number(2 * thresh + 1));
			}
			break;
		case 18:
			str = "双边滤波内核的大小.";
			str.append(QString::number(thresh));
			on_BilateralFilter_triggered();
			break;
		case 19:
			str = "生长邻域梯度的阈值.";
			str.append(QString::number(thresh));
			on_region_grow_triggered();
			break;
		default:
			break;
		}
		ui.label_thresh->setText(str);
	}

	void OpenCVPanel::on_thresh_Slider_1_valueChanged(int value)//thresh_1滑块_1的设置
	{
		thresh_1 = ui.thresh_Slider_1->value();
		QString str;
		switch (flag) {
		case 22:
			str = "迭代次数.";
			on_dilate_image_triggered();
			break;
		case 1:
			str = "迭代次数.";
			on_erode_image_triggered();
			break;
		case 2:
			str = "迭代次数.";
			on_opening_image_triggered();
			break;
		case 3:
			str = "迭代次数.";
			on_closing_image_triggered();
			break;
		case 4:
			str = "迭代次数.";
			on_gradient_image_triggered();
			break;
		case 5:
			str = "迭代次数.";
			on_tophat_image_triggered();
			break;
		case 6:
			str = "迭代次数.";
			on_blackhat_image_triggered();
			break;
		case 7:
			str = "亮度系数.";
			on_contrast_image_triggered();
			break;
		default:
			break;
		}
		str.append(QString::number(thresh_1));
		ui.label_thresh_1->setText(str);
	}

	void OpenCVPanel::on_comboBox1_currentIndexChanged(int index)//选择框1的设置
	{
		switch (ui.comboBox1->currentIndex()) {
		case 0:
			MORPH = 0;
			break;
		case 1:
			MORPH = 1;
			break;
		case 2:
			MORPH = 2;
			break;
		default:
			break;
		}
		on_thresh_Slider_valueChanged(0);
	}

	void OpenCVPanel::on_comboBox2_currentIndexChanged(const QString &arg1)//选择框执行轮廓的描述方法
	{
		on_contours_describe_triggered();
	}

	void OpenCVPanel::on_spinBox_editingFinished()//迭代次数
	{
		interNum = ui.spinBox->value();
		if ((interNum != internum1) && (flag == 21)) on_actionLever_set_triggered();
		if ((interNum != internum1) && (flag == 20)) on_action_FCM_triggered();
	}

	//------------------------图像滤波---------------------//
	void OpenCVPanel::on_BoxFilter_triggered()//方框滤波
	{
		flag = 14;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat dst, src;
		image.copyTo(rep_img);
		image.copyTo(src);
		dst.create(src.size(), src.type());
		boxFilter(src, dst, -1, Size(thresh, thresh));
		img_display(dst);
		setSlider(1, 15, thresh);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("方框滤波后的图."));
		statusBar()->showMessage(tr("已对图像进行方框滤波."));
	}

	void OpenCVPanel::on_MeanBlur_triggered()//均值滤波（邻域平均滤波）
	{
		flag = 15;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat dst, src;
		image.copyTo(rep_img);
		image.copyTo(src);
		dst.create(src.size(), src.type());
		blur(src, dst, Size(thresh, thresh), Point(-1, -1));
		img_display(dst);
		setSlider(1, 15, thresh);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("均值滤波后的图."));
		statusBar()->showMessage(tr("已对图像进行均值滤波."));
	}
	void OpenCVPanel::on_GaussianBlur_triggered()//高斯滤波
	{
		flag = 16;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat dst, src;
		image.copyTo(rep_img);
		image.copyTo(src);
		dst.create(src.size(), src.type());
		GaussianBlur(src, dst, Size(2 * thresh + 1, 2 * thresh + 1), 0, 0);
		img_display(dst);
		setSlider(1, 9, thresh);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("高斯滤波后的图."));
		statusBar()->showMessage(tr("已对图像进行高斯滤波."));
	}
	void OpenCVPanel::on_MedianBlur_triggered()//中值滤波
	{
		flag = 17;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat dst, src;
		image.copyTo(rep_img);
		image.copyTo(src);
		dst.create(src.size(), src.type());
		medianBlur(src, dst, 2 * thresh + 1);
		img_display(dst);
		setSlider(1, 7, thresh);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("中值滤波后的图."));
		statusBar()->showMessage(tr("已对图像进行中值滤波."));
	}
	void OpenCVPanel::on_BilateralFilter_triggered()//双边滤波
	{
		flag = 18;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat dst, src;
		image.copyTo(rep_img);
		image.copyTo(src);
		dst.create(src.size(), src.type());
		bilateralFilter(src, dst, thresh, thresh * 2, thresh / 2);
		img_display(dst);
		setSlider(1, 15, thresh);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("双边滤波后的图."));
		statusBar()->showMessage(tr("已对图像进行双边滤波."));
	}

	//-------------图像分割：大津法阈值分割---------------------//
	void OpenCVPanel::on_OTSU_2_triggered()
	{
		Mat dst, src;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		image.copyTo(rep_img);
		image.copyTo(src);
		dst.create(src.size(), src.type());
		if (src.channels() == 3) { cvtColor(src, src, CV_BGR2GRAY); } //转换为灰度图
		threshold(src, dst, 0, 255, CV_THRESH_OTSU);  //大津法二值化
		img_display(dst);
		dst.copyTo(image);
		ui.tip1->setText(tr("大津法分割后的图."));
		statusBar()->showMessage(tr("已对图像进行大津法阈值分割."));
	}

	//-------------图像分割：边缘检测额分割---------------------//
	void OpenCVPanel::on_actionCanny_triggered()//Canny算子
	{
		flag = 11;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat src, dst, g_cannyDetectedEdges;
		image.copyTo(rep_img);
		image.copyTo(src);
		if (src.channels() == 3) { cvtColor(src, src, CV_BGR2GRAY); } //转换为灰度图
																	  // 先使用 3x3内核来降噪
		blur(src, g_cannyDetectedEdges, Size(3, 3));
		// 运行我们的Canny算子
		Canny(g_cannyDetectedEdges, g_cannyDetectedEdges, thresh, thresh * 3, 3);
		//先将g_dstImage内的所有元素设置为0
		dst.create(src.size(), src.type());
		dst = Scalar::all(0);
		//使用Canny算子输出的边缘图g_cannyDetectedEdges作为掩码，来将原图g_srcImage拷到目标图g_dstImage中
		src.copyTo(dst, g_cannyDetectedEdges);
		img_display(dst);
		if (thresh == 1)thresh = 128;//thresh初始化
		setSlider(0, 255, thresh);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("用Canny算子分割后的图."));
		statusBar()->showMessage(tr("已对图像用Canny算子分割."));
	}
	void OpenCVPanel::on_actionSobel_triggered()//Sobel算子
	{
		flag = 12;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat src, dst, g_sobelGradient_X, g_sobelGradient_Y, g_sobelAbsGradient_X, g_sobelAbsGradient_Y;
		image.copyTo(rep_img);
		image.copyTo(src);
		if (src.channels() == 3) { cvtColor(src, src, CV_BGR2GRAY); } //转换为灰度图
		dst.create(src.size(), src.type());
		// 求 X方向梯度
		Sobel(src, g_sobelGradient_X, CV_16S, 1, 0, thresh, 1, 1, BORDER_DEFAULT);
		convertScaleAbs(g_sobelGradient_X, g_sobelAbsGradient_X);//计算绝对值，并将结果转换成8位
																 // 求Y方向梯度
		Sobel(src, g_sobelGradient_Y, CV_16S, 0, 1, thresh, 1, 1, BORDER_DEFAULT);
		convertScaleAbs(g_sobelGradient_Y, g_sobelAbsGradient_Y);//计算绝对值，并将结果转换成8位
																 // 合并梯度
		addWeighted(g_sobelAbsGradient_X, 0.5, g_sobelAbsGradient_Y, 0.5, 0, dst);

		img_display(dst);
		setSlider(1, 7, thresh);
		ui.thresh_Slider->setPageStep(2);//thresh只能是正奇数
		ui.thresh_Slider->setSingleStep(2);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("用Sobel算子分割后的图."));
		statusBar()->showMessage(tr("已对图像用Sobel算子分割."));
	}

	void OpenCVPanel::on_actionLaplacian_triggered()//Laplacian算子
	{
		flag = 13;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat src, dst, g_cannyDetectedEdges;
		image.copyTo(rep_img);
		image.copyTo(src);
		if (src.channels() == 3)
		{
			cvtColor(src, src, CV_BGR2GRAY);
		} //转换为灰度图
		GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
		Laplacian(src, dst, CV_16S, thresh, 1, 0, BORDER_DEFAULT);
		convertScaleAbs(dst, dst); //计算绝对值，并将结果转换成8位
		img_display(dst);
		setSlider(1, 7, thresh);
		ui.thresh_Slider->setPageStep(2);//thresh只能是正奇数
		ui.thresh_Slider->setSingleStep(2);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("用Laplacian算子分割后的图."));
		statusBar()->showMessage(tr("已对图像用Laplacian算子分割."));
	}

	//-------------基于区域的分割:区域生长法---------------------//
	void OpenCVPanel::on_region_grow_triggered()
	{
		flag = 19;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		Mat src;
		image.copyTo(rep_img);
		image.copyTo(src);
		IplImage imgTmp = src;  //Mat类型转换到IplImage类型
		IplImage *tmp = cvCloneImage(&imgTmp);
		IplImage* newimg = cvCreateImage(cvSize(tmp->width, tmp->height), 8, 3);
		int i;  //---循环变量
		int j;
		int k = 0;
		int height = tmp->height;
		int wide = tmp->width;
		int   zhongzi = 0;
		int   zhongzi2 = 0;
		int   zhongzi3 = 0;
		for (i = height / 2 - 4; i<height / 2 + 5; i++)
		{
			for (j = wide / 2 - 4; j<wide / 2 + 5; j++)
			{
				zhongzi += ((uchar*)(tmp->imageData + tmp->widthStep*i))[j * 3];
				zhongzi2 += ((uchar*)(tmp->imageData + tmp->widthStep*i))[j * 3 + 1];
				zhongzi3 += ((uchar*)(tmp->imageData + tmp->widthStep*i))[j * 3 + 2];
				k++;
			}
		}
		zhongzi = zhongzi / k;
		zhongzi2 = zhongzi2 / k;
		zhongzi3 = zhongzi3 / k;

		for (j = 0; j < height; j++)                //---对各像素进行灰度转换
		{
			for (i = 0; i < wide; i++)
			{
				int  temp = ((uchar*)(tmp->imageData + tmp->widthStep*j))[i * 3];
				int  temp2 = ((uchar*)(tmp->imageData + tmp->widthStep*j))[i * 3 + 1];
				int  temp3 = ((uchar*)(tmp->imageData + tmp->widthStep*j))[i * 3 + 2];
				if (abs(temp - zhongzi)<thresh&&abs(temp2 - zhongzi2)<thresh&&abs(temp3 - zhongzi3)<thresh)    //当前点同种子一灰度值比较接近
				{								     //---将种子的颜色贴到当前位置
					((newimg->imageData + newimg->widthStep*j)[i * 3]) = temp;
					((newimg->imageData + newimg->widthStep*j)[i * 3 + 1]) = temp2;
					((newimg->imageData + newimg->widthStep*j)[i * 3 + 2]) = temp3;
				}
			}
		}

		//cv::Mat dst(newimg);
		Mat dst = cvarrToMat(newimg);
		img_display(dst);
		if (thresh == 1)thresh = 60;//thresh初始化
		setSlider(1, 255, thresh);
		dst.copyTo(dst_image);
		ui.tip1->setText(tr("用区域生长法分割后的图."));
		statusBar()->showMessage(tr("已对图像用区域生长法分割."));
	}

	//-------------基于形态学的分割---------------------//
	void OpenCVPanel::on_watershed_2_triggered()//分水岭算法
	{
		Mat dst, src, binary;
		image.copyTo(rep_img);
		image.copyTo(src);
		if (src.channels() == 1)
			cvtColor(src, src, CV_GRAY2RGB);//输入图像必须是8UC3
		src.convertTo(src, CV_8UC3);

		cvtColor(src, binary, CV_BGR2GRAY);
		threshold(binary, binary, 0, 255, CV_THRESH_OTSU);  //大津法二值化

															// Eliminate noise and smaller objects
		cv::Mat fg;
		cv::erode(binary, fg, cv::Mat(), cv::Point(-1, -1), 2);

		// Identify image pixels without objects
		cv::Mat bg;
		cv::dilate(binary, bg, cv::Mat(), cv::Point(-1, -1), 3);
		cv::threshold(bg, bg, 1, 128, cv::THRESH_BINARY_INV);

		// Create markers image
		cv::Mat markers(binary.size(), CV_8U, cv::Scalar(0));
		markers = fg + bg;
		markers.convertTo(markers, CV_32S);

		watershed(src, markers);
		markers.convertTo(dst, CV_8U);

		img_display(dst);
		dst.copyTo(image);
		ui.tip1->setText(tr("用分水岭算法分割后的图."));
		statusBar()->showMessage(tr("已对图像用分水岭算法分割."));

	}

	//-------------基于图论的分割---------------------//
	void OpenCVPanel::on_GrabCut_triggered()//Grab_Cut
	{
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		if (!(QMessageBox::information(this, tr("提示"), tr("请用鼠标拖拽处可能是前景的矩形区域."), tr("Yes"), tr("No"))))
		{
			flag = 21;
		}
		else
			return;
	}

	//IplImage* K_Means(IplImage* src)//K均值聚类
	//{
	//	int i, j, k = 0, value;
	//	int nCuster = 2;//给定聚类数目
	//					//定义数组cluster用以标志每个样本对应的类别，取值范围0,1,2...nCuster-1;
	//	CvMat* clusters = cvCreateMat(src->height*src->width, 1, CV_32SC1);//Opencv内部函数cvKMeans2要求label数组必须是CV_32SC1型
	//	CvMat* samples = cvCreateMat(src->height*src->width, 1, CV_32FC2);//要求sampels数组必须是CV_32FC2型
	//	IplImage* dst = cvCreateImage(cvGetSize(src), 8, 1);
	//	for (i = 0; i<src->width; i++)
	//		for (j = 0; j<src->height; j++)
	//		{
	//			CvScalar s;
	//			//获取图像各个像素点的三通道值(BGR)
	//			s.val[0] = (float)cvGet2D(src, j, i).val[0];
	//			s.val[1] = (float)cvGet2D(src, j, i).val[1];
	//			s.val[2] = (float)cvGet2D(src, j, i).val[2];
	//			cvSet2D(samples, k++, 0, s);

	//		}

	//	cvKMeans2(samples, nCuster, clusters, cvTermCriteria(CV_TERMCRIT_ITER, 100, 1.0));
	//	//绘制聚类后的图像
	//	k = 0;
	//	float step = 255 / (nCuster - 1);
	//	for (i = 0; i<src->width; i++)
	//	{
	//		for (j = 0; j<src->height; j++)
	//		{
	//			value = clusters->data.i[k++];
	//			CvScalar s;
	//			s.val[0] = 255 - value*step;
	//			cvSet2D(dst, j, i, s);

	//		}
	//	}
	//	return(dst);
	//}
	//-------------基于聚类的分割---------------------//
	void OpenCVPanel::on_action_K_Means_triggered()//K-Means
	{
		//if (!image.data)
		//{
		//	QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
		//	return;
		//}
		//Mat src;
		//image.copyTo(rep_img);
		//image.copyTo(src);
		//IplImage imgTmp = src;  //Mat类型转换到IplImage类型
		//IplImage *tmp = cvCloneImage(&imgTmp);
		//IplImage* newimg = cvCreateImage(cvSize(tmp->width, tmp->height), 8, 1);
		//newimg = K_Means(tmp);
		//Mat dst = cvarrToMat(newimg);
		//img_display(dst);
		//dst.copyTo(dst_image);
		//ui.tip1->setText(tr("用K-Means聚类分割后的图."));
		//statusBar()->showMessage(tr("已对图像用K-Means聚类分割."));
	}

	//模糊C聚类算法准备函数:完成数据极差标准化处理
	double** Standardize(double **data, int row, int col)
	{
		int i, j;
		double *a = new double[col];//矩阵每列最大值
		double *b = new double[col];//矩阵每列最小值
		double *c = new double[row];//用以暂时存储矩阵某一列元素
		for (i = 0; i<col; i++)
		{
			//取出数据矩阵的各列元素
			for (j = 0; j<row; j++)
			{
				c[j] = data[j][i];
			}
			a[i] = c[0];
			b[i] = c[0];
			for (j = 0; j<row; j++)
			{
				//列最大值
				if (c[j]>a[i])
					a[i] = c[j];
				//列最小值
				if (c[j]<b[i])
					b[i] = c[j];
			}
		}
		for (i = 0; i<row; i++)
		{
			for (j = 0; j<col; j++)
			{
				data[i][j] = (data[i][j] - b[j]) / (a[j] - b[j]);
			}
		}
		delete[]a;
		delete[]b;
		delete[]c;

		return(data);

	}
	//生成样本隶属度矩阵
	void Initialize(double **u, int k, int row)//k为聚类数
	{
		int i, j;
		//初始化样本隶属度矩阵
		//srand((unsigned)time(0));
		for (i = 0; i<k; i++)
		{
			for (j = 0; j<row; j++)
			{
				u[i][j] = (double)rand() / RAND_MAX;//隶属度取值范围设为0~1
			}//rand()函数返回0~RANDN_MAX之间的一个伪随机数
		}
		//隶属度数据归一化
		double *sum = new double[row];//隶属度矩阵每列的和
		for (j = 0; j<row; j++)//这里用row表示列数不是拼写错误而是因为隶属度矩阵的列数等于data矩阵的行数，row是data矩阵的行
		{
			double dj = 0;
			for (i = 0; i<k; i++)
			{
				dj += u[i][j];
			}
			sum[j] = dj;//隶属度矩阵各列之和

		}
		for (i = 0; i<k; i++)
		{
			for (j = 0; j<row; j++)
			{
				u[i][j] /= sum[j];//归一化
			}
		}

		delete[]sum;
	}
	//迭代函数
	double Update(double **u, double **data, double **center, int row, int col, int k, int m, double **U, double **dis, double *a, double *b)
	{
		int i, j, t;
		double si = 0;//center(i,j) 的分子
		double sj = 0;//center(i,j) 的分母
					  //根据隶属度矩阵计算聚类中心，参见论文3.4式
		for (i = 0; i<k; i++)
		{
			for (j = 0; j<row; j++)
			{
				U[i][j] = pow(u[i][j], m);//m为模糊指数，越高越模糊，越小越接近K均值聚类
			}

		}
		for (j = 0; j<col; j++)
		{
			for (i = 0; i<k; i++)
			{
				for (t = 0; t<row; t++)
				{
					si += U[i][t] * data[t][j];
					sj += U[i][t];
				}
				center[i][j] = si / sj;
			}
		}
		//计算各个聚类中心i分别到所有点j的距离矩阵dis(i,j)
		/*double *a=new double[col];
		double *b=new double[col];
		double **dis=new double *[k];//聚类中心与样本之间的距离矩阵

		for(i=0;i<k;i++)
		{
		dis[i]=new double[row];
		}*/
		for (i = 0; i<k; i++)
		{
			for (j = 0; j<col; j++)
				a[j] = center[i][j];//暂存一个类中心
			for (j = 0; j<row; j++)
			{
				for (t = 0; t<col; t++)
					b[t] = data[j][t];//暂存一个样本
				double d = 0;
				//计算聚类中心与样本之间的距离
				for (t = 0; t<col; t++)
				{
					d += (a[t] - b[t])*(a[t] - b[t]);//d为一个中心与一个样本的欧几里得距离的平方
				}
				dis[i][j] = sqrt(d);//欧几里得距离
			}
		}
		//隶属度矩阵的更新，参见论文的3.5式
		for (i = 0; i<k; i++)
		{
			for (j = 0; j<row; j++)
			{
				double temp = 0;
				for (t = 0; t<k; t++)
				{
					//模糊指数为m
					temp += pow(dis[i][j] / dis[t][j], 2 / (m - 1));
				}
				u[i][j] = 1 / temp;
			}
		}
		//根据FCM的价值函数（目标函数）计算聚类有效性评价参数参见论文中3.2式
		double func1 = 0;
		for (i = 0; i<k; i++)
		{
			double func2 = 0;
			for (j = 0; j<row; j++)
			{
				func2 += U[i][j] * (dis[i][j] * dis[i][j]);
			}
			func1 += func2;
		}
		double obj_fun = func1;
		//double obj_fun=1/(1+func1);
		return(obj_fun);
		/*
		//内存释放
		for(j=0;j<k;j++)
		{
		delete[]U[j];
		}
		delete[]U;
		delete[]a;
		delete[]b;
		for(i=0;i<k;i++)
		delete[]dis[i];
		delete[]dis;
		*/
	}
	//do_FCM需要调用上述函数
	//IplImage* do_FCM(IplImage* src)
	//{

	//	double **data;//数据矩阵（一个像素一行）
	//	double **center;//聚类中心矩阵
	//	double **u;//样本隶属度矩阵
	//	int m;//模糊指数
	//	int row = src->width*src->height;//样本总数
	//	int col = src->nChannels;//样本属性数（图像通道数）
	//							 //cout<<"图像尺寸："<<src->width<<'*'<<src->height<<endl;//图像尺寸直接关系到处理数据的规模
	//	int k;//设定划分的类别
	//		  //cout<<"请输入模糊指数m："<<endl;
	//		  //cin>>m;
	//	m = 2;//m为模糊指数，越高越模糊，越小越接近K均值聚类
	//		  //cout<<"请输入聚类数目k："<<endl;
	//		  //cin>>k;
	//	k = 2;
	//	int mum;//算法运行次数
	//			//cout<<"设定迭代次数上限"<<endl;
	//			//cin>>mum;
	//	mum = interNum;
	//	//各次运行结束后的目标函数值
	//	double *Index = new double[mum];

	//	//FCM聚类算法开始运行，次数上限mum
	//	int i, j, t;
	//	data = new double *[row];
	//	for (i = 0; i<row; i++)
	//	{
	//		data[i] = new double[col];
	//	}
	//	t = 0;
	//	//下面这部分的数据定义主要是为了避免内存耗尽的发生从Update函数中搬下来的
	//	double **U = new double *[k]; //为了计算方便定义的二维数组U,U[i][j]=pow(u[i][j],m);
	//	for (j = 0; j<k; j++)
	//	{
	//		U[j] = new double[row];
	//	}
	//	double *a = new double[col];
	//	double *b = new double[col];
	//	double **dis = new double *[k];//聚类中心与样本之间的距离矩阵

	//	for (i = 0; i<k; i++)
	//	{
	//		dis[i] = new double[row];
	//	}
	//	////////////////////////////
	//	//图像数据提取
	//	for (i = 0; i<src->width; i++)
	//		for (j = 0; j<src->height; j++)
	//		{

	//			for (int t1 = 0; t1<col; t1++)
	//			{
	//				data[t][t1] = (double)cvGet2D(src, j, i).val[t1];
	//			}
	//			t++;
	//		}//将图像中的像素各通道强度值存入数组data中，每个像素一行


	//	double eps = 1e-4;
	//	int e = 0;//迭代次数循环控制变量

	//			  //记录连续无改进次数
	//	int nx = 0;
	//	//数据极差标准化处理
	//	data = Standardize(data, row, col);
	//	/////////////////////以上内容没问题////////////////////////


	//	//聚类中心及隶属度矩阵的内存分配
	//	center = new double *[k];
	//	u = new double *[k];
	//	for (j = 0; j<k; j++)
	//	{
	//		center[j] = new double[col];
	//		u[j] = new double[row];
	//	}
	//	//生成隶属度矩阵（初始化后归一化）
	//	Initialize(u, k, row);


	//	//目标函数连续10代无改进，停止该次聚类迭代过程
	//	for (i = 0; i<mum; i++)
	//	{

	//		//聚类迭代过程
	//		Index[nx] = Update(u, data, center, row, col, k, m, U, dis, a, b);

	//		if (nx>0 && abs(Index[nx] - Index[nx - 1])<eps)
	//			e++;
	//		else
	//			e = 0;
	//		nx++;
	//		//cout<<nx<<'\t'<<e<<endl;
	//		if (e >= 10)
	//			break;

	//	}


	//	//绘制聚类后图像
	//	int t1 = 0;
	//	double step = 255 / (k - 1);
	//	IplImage* dst = cvCreateImage(cvGetSize(src), 8, 1);
	//	for (i = 0; i<src->width; i++)
	//	{
	//		for (j = 0; j<src->height; j++)
	//		{

	//			CvScalar s;
	//			s.val[0] = 0;
	//			for (t = 0; t<k; t++)
	//			{
	//				s.val[0] += (255 - t*step)*u[t][t1];
	//			}
	//			cvSet2D(dst, j, i, s);
	//			t1++;
	//		}

	//	}
	//	return(dst);

	//	//内存释放
	//	for (j = 0; j<k; j++)
	//	{
	//		delete[]center[j];
	//		delete[]u[j];
	//	}
	//	for (j = 0; j<col; j++)
	//	{
	//		delete[]data[j];

	//	}
	//	delete[]data;
	//	for (j = 0; j<k; j++)
	//	{
	//		delete[]U[j];
	//	}
	//	delete[]U;
	//	delete[]a;
	//	delete[]b;
	//	for (i = 0; i<k; i++)
	//		delete[]dis[i];
	//	delete[]dis;
	//	delete[]center;
	//	delete[]u;
	//	delete[]Index;

	//}
	void OpenCVPanel::on_action_FCM_triggered()//FCM
	{
		flag = 20;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		ui.spinBox->setVisible(true);
		ui.label_thresh->setVisible(true);
		QString str;
		str = "聚类数为:2，迭代次数:";
		str.append(QString::number(interNum));
		ui.label_thresh->setText(str);
		internum1 = interNum;
		//Mat src;
		//image.copyTo(rep_img);
		//image.copyTo(src);
		//IplImage imgTmp = src;  //Mat类型转换到IplImage类型
		//IplImage *tmp = cvCloneImage(&imgTmp);
		//double t = (double)getTickCount();//计时
		//IplImage*newimg = do_FCM(tmp);
		//t = ((double)getTickCount() - t - interNum) / getTickFrequency();
		//ui.label_thresh_1->setVisible(true);
		//QString str1;
		//str1 = "用时(秒).";
		//str1.append(QString::number(t));
		//ui.label_thresh_1->setText(str1);
		////cv::Mat dst(newimg);
		//Mat dst = cvarrToMat(newimg);
		//img_display(dst);
		//dst.copyTo(dst_image);
		ui.tip1->setText(tr("用FCM聚类分割后的图."));
		statusBar()->showMessage(tr("已对图像用FCM聚类分割."));
	}

	//-------------基于活动轮廓模型的分割----------------//
	void OpenCVPanel::on_actionLever_set_triggered()//Lever set
	{
		flag = 21;
		if (!image.data)
		{
			QMessageBox::warning(this, tr("Warning"), tr("请先打开图片."));
			return;
		}
		ui.spinBox->setVisible(true);
		ui.label_thresh->setVisible(true);
		ui.label_thresh_1->setVisible(true);
		QString str;
		str = "迭代次数:";
		str.append(QString::number(interNum));
		ui.label_thresh->setText(str);
		internum1 = interNum;
		//cvWaitKey(100);
		//Mat src;
		//image.copyTo(rep_img);
		//image.copyTo(src);
		//IplImage imgTmp = src;  //Mat类型转换到IplImage类型
		//IplImage *imgOrig = cvCloneImage(&imgTmp);
		//leverset ls;
		//IplImage *imgGray = ls.getGray(imgOrig);
		//int i, j;
		//CvScalar cur1, cur2, cur;
		//CvSize size = cvSize(imgOrig->width, imgOrig->height);
		//IplImage *imgGauss = cvCreateImage(size, IPL_DEPTH_32F, 1);
		//IplImage *Ix = cvCreateImage(size, IPL_DEPTH_32F, 1);
		//IplImage *Iy = cvCreateImage(size, IPL_DEPTH_32F, 1);
		//IplImage *imgG = cvCreateImage(size, IPL_DEPTH_32F, 1);
		//IplImage *imgU = cvCreateImage(size, IPL_DEPTH_32F, 1);
		//IplImage *imgDisplay = cvCreateImage(size, IPL_DEPTH_8U, 3);

		//double epsilon = 1.5; // the papramater in the definition of smoothed Dirac function
		//double timestep = 7;
		//double mu = 0.2 / timestep;  // coefficient of the internal (penalizing) energy term P
		//							 // Note: the product timestep*mu must be less than 0.25 for stability!
		//double lambda = 5; // coefficient of the weighted length term Lg
		//double alf = 1.5;  // coefficient of the weighted area term Ag
		//				   // Note: Choose a positive(negative) alf if the initial contour is outside(inside) the object.
		//double c0 = 4.0;
		//int w = 5;	//initial boundary

		//cvSmooth(imgGray, imgGauss, CV_GAUSSIAN, 0, 0, 1.5, 0);
		//ls.Sobel(imgGauss, Ix, Iy);
		//for (i = 0; i<size.height; i++)
		//{
		//	for (j = 0; j<size.width; j++)
		//	{
		//		cur1 = cvGet2D(Ix, i, j);
		//		cur2 = cvGet2D(Iy, i, j);
		//		cur.val[0] = 1.0 / (1.0 + cur1.val[0] * cur1.val[0] + cur2.val[0] * cur2.val[0]);
		//		cvSet2D(imgG, i, j, cur);
		//	}
		//}

		////define initial level set function (LSF) as -c0, 0, c0 at points outside, on
		////the boundary, and inside of a region R, respectively.
		//for (i = 0; i<size.height; i++)
		//{
		//	for (j = 0; j<size.width; j++)
		//	{
		//		if (i<w || i>size.height - w - 1 || j<w || j>size.width - w - 1)
		//		{
		//			cur.val[0] = c0;
		//		}
		//		else if (i>w && i<size.height - w - 1 && j>w && j<size.width - w - 1)
		//		{
		//			cur.val[0] = -c0;
		//		}
		//		else cur.val[0] = 0;
		//		// Note: this can be commented out. The intial LSF does NOT necessarily need a zero level set.
		//		cvSet2D(imgU, i, j, cur);
		//	}
		//}

		//ls.ImgDraw(imgOrig, imgU, imgDisplay);
		//namedWindow("LevelSet", WINDOW_AUTOSIZE);
		//cvShowImage("LevelSet", imgDisplay);

		//double t = (double)getTickCount();//计时
		//float count;
		//for (int k = 0; k<interNum; k++)
		//{
		//	ls.EVolution(imgU, imgG, lambda, mu, alf, epsilon, timestep, 1);
		//	if (k % 10 == 0)
		//	{
		//		ls.ImgDraw(imgOrig, imgU, imgDisplay);
		//		cvShowImage("LevelSet", imgDisplay);
		//		cvWaitKey(10);
		//	}
		//	str = "正在迭代第:";
		//	str.append(QString::number(k + 1));
		//	str.append("次.");
		//	ui.label_thresh->setText(str);
		//}
		//t = ((double)getTickCount() - t - interNum) / getTickFrequency();;
		//QString str1;
		//str1 = "用时(秒):";
		//str1.append(QString::number(t));
		//ui.label_thresh_1->setText(str1);
		////cv::Mat dst(imgDisplay);
		//Mat dst = cvarrToMat(imgDisplay);
		//img_display(dst);
		//dst.copyTo(dst_image);
		//cvWaitKey(50);
		//cvDestroyWindow("LevelSet");
		//cvReleaseImage(&imgGauss);
		//cvReleaseImage(&Ix);
		//cvReleaseImage(&Iy);
		//cvReleaseImage(&imgG);
		//cvReleaseImage(&imgU);
		//cvReleaseImage(&imgDisplay);
		//cvReleaseImage(&imgOrig);
		//cvReleaseImage(&imgGray);
		//ui.tip1->setText(tr("用Leverset分割后的图."));
		//statusBar()->showMessage(tr("已对图像用Leverset分割."));

	}	

} // namespace general_demo


