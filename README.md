# Histogram-Equalization-Specification-Demo

This project help you understand the concepts of histogram equalization and histogram specification in image processing learning from a programming perspective. 

## Usage

For each single `cpp` file, you can:

```shell
g++ <>.cpp -o <name>
./<name>
```

## Demo

![image](https://user-images.githubusercontent.com/35065046/222942157-7bfd9eac-d278-4c13-b5fe-9407e699f906.png)

## Principle of Histogram

The histogram is a graphical representation of the distribution of pixel intensities in an image. It provides valuable information about the contrast and brightness levels present in the image. The principle of a histogram is based on the statistical analysis of pixel intensities.

The histogram consists of a horizontal axis representing the range of pixel intensities and a vertical axis representing the frequency of occurrence of each intensity value. The intensity values are usually divided into discrete bins or intervals, and the height of each bin represents the number of pixels with intensities falling within that range.

The principle behind the histogram is to analyze the distribution of pixel intensities in an image to gain insights into its characteristics. By examining the histogram, one can determine the overall brightness, contrast, and dynamic range of the image. It helps in understanding whether the image is predominantly dark or bright or if it has a balanced distribution of intensities.

The histogram is a useful tool in various image processing tasks, such as image enhancement, thresholding, and equalization. It allows us to make informed decisions about how to manipulate the pixel intensities to achieve desired results.

## Principle of Histogram Equalization

Histogram equalization is a technique used to enhance the contrast of an image by redistributing the pixel intensities. The principle of histogram equalization is based on the idea of transforming the original histogram of an image to a new histogram that has a more uniform distribution.

The process of histogram equalization involves the following steps:

1. Compute the histogram of the input image.
2. Calculate the cumulative distribution function (CDF) of the histogram.
3. Normalize the CDF to the range of intensity values in the image.
4. Map the input intensities to new intensities based on the normalized CDF.

The goal of histogram equalization is to stretch the intensity range of the image such that the darker regions become darker and the brighter regions become brighter. This results in an image with enhanced contrast and improved visual appearance.

Histogram equalization is particularly effective when an image has a narrow or uneven distribution of intensity values. However, it may also amplify noise or other unwanted artifacts present in the image. Therefore, it is often used in conjunction with other image enhancement techniques to achieve the desired results.

## Principle of Histograme Specification

Histogram specification, also known as histogram matching or histogram matching, is a technique used to modify the histogram of an image to match a specified histogram. The principle of histogram specification involves transforming the pixel intensities in an image to match a desired histogram while preserving the overall structure and content of the original image.

The process of histogram specification involves the following steps:

1. Compute the histograms of both the input image and the desired histogram.
2. Calculate the cumulative distribution functions (CDFs) of both histograms.
3. Normalize the CDFs to the range of intensity values in the image and the desired histogram.
4. Map the input intensities to new intensities based on the normalized CDFs.

The goal of histogram specification is to modify the pixel intensities in such a way that the resulting image has a histogram that closely resembles the desired histogram. This allows for the transfer of specific characteristics, such as contrast, brightness, or color distribution, from one image to another.

Histogram specification is commonly used in various image processing applications, including image matching, color correction, and image fusion. It provides a flexible means of adjusting the visual appearance of an image to meet specific requirements or match a reference image.
