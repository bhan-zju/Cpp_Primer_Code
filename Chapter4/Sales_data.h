#ifndef SALES_DATA_H     // ͷ�ļ�����������Ϊ�������ΪSALES_DATA_H��Ԥ�������δ����Ϊ�棨��δ�����壩����ִ�к���ֱ��endif
#define SALES_DATA_H     // ����Ԥ�������SALES_DATA_H

#include <string>
struct Sales_data
{
    std::string bookNO;       // ͼ��ISBN���    ��ʼ��Ϊ�մ�����ռ�ڴ�
    unsigned units_sold = 0;      // ��������    ռ4
    double revenue = 0.0;           // ����      ռ8
};

#endif // !SALES_DATA_H    // endif

