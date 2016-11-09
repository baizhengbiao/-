// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
using namespace std;

//  ����뾶 ��λ��
double EARTH_RADIUS = 6378137;

// �Ƕȵ����ȵ�ת��
double rad(double d)
{
	return d * M_PI / 180.0;
}
/*
	longitude ����
	latitude  ά��
	����1 ��γ�ȣ�lon1 , lat1�� 
	����2 ��γ�ȣ�lon2 , lat2��
	���ؼ���������ֱ�߾��루��λ�ף� dist
*/
double LantitudeLongitudeDist(double lon1, double lat1, double lon2, double lat2) {
	double radLat1 = rad(lat1);
	double radLat2 = rad(lat2);

	double radLon1 = rad(lon1);
	double radLon2 = rad(lon2);

	if (radLat1 < 0)
		radLat1 = M_PI / 2 + abs(radLat1);  
	if (radLat1 > 0)
		radLat1 = M_PI / 2 - abs(radLat1);  
	if (radLon1 < 0)
		radLon1 = M_PI * 2 - abs(radLon1);  
	if (radLat2 < 0)
		radLat2 = M_PI / 2 + abs(radLat2);  
	if (radLat2 > 0)
		radLat2 = M_PI / 2 - abs(radLat2);  
	if (radLon2 < 0)
		radLon2 = M_PI * 2 - abs(radLon2);  
	double x1 = EARTH_RADIUS * cos(radLon1) * sin(radLat1);
	double y1 = EARTH_RADIUS * sin(radLon1) * sin(radLat1);
	double z1 = EARTH_RADIUS * cos(radLat1);

	double x2 = EARTH_RADIUS * cos(radLon2) * sin(radLat2);
	double y2 = EARTH_RADIUS * sin(radLon2) * sin(radLat2);
	double z2 = EARTH_RADIUS * cos(radLat2);

	double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
	//���Ҷ�����н�  
	double theta = acos((EARTH_RADIUS * EARTH_RADIUS + EARTH_RADIUS * EARTH_RADIUS - d * d) / (2 * EARTH_RADIUS * EARTH_RADIUS));
	double dist = theta * EARTH_RADIUS;
	return dist;
}
int _tmain(int argc, _TCHAR* argv[])
{
	double lon1 = 116.44927203908522;
	double lat1 = 39.922922108018767 ;	
	double lon2 = 113.26408;
	double lat2 = 23.155112;	
	double dist = LantitudeLongitudeDist(lon1, lat1, lon2, lat2);
	std::cout << "���룺"<< dist << std::endl;
	int i;
	cin>>i;
	return 0;
}

