#ifndef SALES_DATA_H     // ͷ�ļ�����������Ϊ�������ΪSALES_DATA_H��Ԥ�������δ����Ϊ�棨��δ�����壩����ִ�к���ֱ��endif
#define SALES_DATA_H     // ����Ԥ�������SALES_DATA_H

#include <string>
struct Sales_data
{
    std::string bookNO;       // ͼ��ISBN���
    unsigned units_sold = 0;      // ��������
    double revenue = 0.0;           // ����
};

#endif // !SALES_DATA_H    // endif

