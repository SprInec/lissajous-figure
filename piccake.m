clc
clear
img=imread('F:\Embedded Development\Software\STM32 Project\Base MKD Keil\Lisaru\image\dx.jpg');   %读取到一张图片
i = imresize(img,[1024,1024]);
[Height,Width]=size(i);                 %获取原图像的高度和宽度
T1=affine2d([-1 0 0;0 1 0;Width 0 1]);  %构造空间变换结构T1，这里为水平镜像变换矩阵
i=imwarp(i,T1);                         %对原图像I进行水平镜像变换  
thresh = graythresh(i);                 %自动确定二值化阈值
i2 = im2bw(i,thresh);                   %对图像二值化

% figure(1)
% imshow(i)     %显示二值化之前的图片
% figure(2)
% imshow(I2)    %显示二值化之后的图片



i3 =~i2;
figure(3)
PicEdge6=edge(i3,'roberts');
PicEdge7=edge(PicEdge6,'roberts');
imshow(PicEdge7)

[m,n] =find(PicEdge7==1);
m = m*4;
n= n*4;
m = 4096-m;
n= 4096-n;
fid = fopen('y.txt','wt');
fprintf(fid,'%g,',m);       
fclose(fid)
fid = fopen('x.txt','wt');
fprintf(fid,'%g,',n);       
fclose(fid)