#ifndef BUF_SIZEMAX 
#error add -DBUF_SIZEMAX=128 on the compile command line
#else
#if BUF_SIZEMAX < 128
#error BUF_SIZEMAX too small, it must be at least 128
#endif
#endif

#include "globals.h"

#ifndef _H
#define _H
#ifdef __cplusplus
extern "C" {
#endif



typedef struct {
	float A_re[32];
	float A_im[32];
	int idx;
} FloatSource_1069_t;
void FloatSource(buffer_float_t *chanout);
void FloatSource_1069();
void Pre_CollapsedDataParallel_1(buffer_float_t *chanin, buffer_float_t *chanout);
void Pre_CollapsedDataParallel_1_1370();
void WEIGHTED_ROUND_ROBIN_Splitter_1512();
void Butterfly(buffer_float_t *chanin, buffer_float_t *chanout);
void Butterfly_1514();
void Butterfly_1515();
void Butterfly_1516();
void Butterfly_1517();
void Butterfly_1518();
void Butterfly_1519();
void Butterfly_1520();
void Butterfly_1521();
void Butterfly_1522();
void Butterfly_1523();
void Butterfly_1524();
void Butterfly_1525();
void Butterfly_1526();
void Butterfly_1527();
void Butterfly_1528();
void Butterfly_1529();
void WEIGHTED_ROUND_ROBIN_Joiner_1513();
void Post_CollapsedDataParallel_2(buffer_float_t *chanin, buffer_float_t *chanout);
void Post_CollapsedDataParallel_2_1371();
void WEIGHTED_ROUND_ROBIN_Splitter_1414();
void Pre_CollapsedDataParallel_1_1373();
void WEIGHTED_ROUND_ROBIN_Splitter_1530();
void Butterfly_1532();
void Butterfly_1533();
void Butterfly_1534();
void Butterfly_1535();
void Butterfly_1536();
void Butterfly_1537();
void Butterfly_1538();
void Butterfly_1539();
void WEIGHTED_ROUND_ROBIN_Joiner_1531();
void Post_CollapsedDataParallel_2_1374();
void WEIGHTED_ROUND_ROBIN_Splitter_1494();
void Pre_CollapsedDataParallel_1_1379();
void WEIGHTED_ROUND_ROBIN_Splitter_1540();
void Butterfly_1542();
void Butterfly_1543();
void Butterfly_1544();
void Butterfly_1545();
void WEIGHTED_ROUND_ROBIN_Joiner_1541();
void Post_CollapsedDataParallel_2_1380();
void Pre_CollapsedDataParallel_1_1382();
void WEIGHTED_ROUND_ROBIN_Splitter_1546();
void Butterfly_1548();
void Butterfly_1549();
void Butterfly_1550();
void Butterfly_1551();
void WEIGHTED_ROUND_ROBIN_Joiner_1547();
void Post_CollapsedDataParallel_2_1383();
void WEIGHTED_ROUND_ROBIN_Joiner_1495();
void Pre_CollapsedDataParallel_1_1376();
void WEIGHTED_ROUND_ROBIN_Splitter_1552();
void Butterfly_1554();
void Butterfly_1555();
void Butterfly_1556();
void Butterfly_1557();
void Butterfly_1558();
void Butterfly_1559();
void Butterfly_1560();
void Butterfly_1561();
void WEIGHTED_ROUND_ROBIN_Joiner_1553();
void Post_CollapsedDataParallel_2_1377();
void WEIGHTED_ROUND_ROBIN_Splitter_1496();
void Pre_CollapsedDataParallel_1_1385();
void WEIGHTED_ROUND_ROBIN_Splitter_1562();
void Butterfly_1564();
void Butterfly_1565();
void Butterfly_1566();
void Butterfly_1567();
void WEIGHTED_ROUND_ROBIN_Joiner_1563();
void Post_CollapsedDataParallel_2_1386();
void Pre_CollapsedDataParallel_1_1388();
void WEIGHTED_ROUND_ROBIN_Splitter_1568();
void Butterfly_1570();
void Butterfly_1571();
void Butterfly_1572();
void Butterfly_1573();
void WEIGHTED_ROUND_ROBIN_Joiner_1569();
void Post_CollapsedDataParallel_2_1389();
void WEIGHTED_ROUND_ROBIN_Joiner_1497();
void WEIGHTED_ROUND_ROBIN_Joiner_1498();
void WEIGHTED_ROUND_ROBIN_Splitter_1499();
void WEIGHTED_ROUND_ROBIN_Splitter_1500();
void Pre_CollapsedDataParallel_1_1391();
void WEIGHTED_ROUND_ROBIN_Splitter_1574();
void Butterfly_1576();
void Butterfly_1577();
void WEIGHTED_ROUND_ROBIN_Joiner_1575();
void Post_CollapsedDataParallel_2_1392();
void Pre_CollapsedDataParallel_1_1394();
void WEIGHTED_ROUND_ROBIN_Splitter_1578();
void Butterfly_1580();
void Butterfly_1581();
void WEIGHTED_ROUND_ROBIN_Joiner_1579();
void Post_CollapsedDataParallel_2_1395();
void Pre_CollapsedDataParallel_1_1397();
void WEIGHTED_ROUND_ROBIN_Splitter_1582();
void Butterfly_1584();
void Butterfly_1585();
void WEIGHTED_ROUND_ROBIN_Joiner_1583();
void Post_CollapsedDataParallel_2_1398();
void Pre_CollapsedDataParallel_1_1400();
void WEIGHTED_ROUND_ROBIN_Splitter_1586();
void Butterfly_1588();
void Butterfly_1589();
void WEIGHTED_ROUND_ROBIN_Joiner_1587();
void Post_CollapsedDataParallel_2_1401();
void WEIGHTED_ROUND_ROBIN_Joiner_1501();
void WEIGHTED_ROUND_ROBIN_Splitter_1502();
void Pre_CollapsedDataParallel_1_1403();
void WEIGHTED_ROUND_ROBIN_Splitter_1590();
void Butterfly_1592();
void Butterfly_1593();
void WEIGHTED_ROUND_ROBIN_Joiner_1591();
void Post_CollapsedDataParallel_2_1404();
void Pre_CollapsedDataParallel_1_1406();
void WEIGHTED_ROUND_ROBIN_Splitter_1594();
void Butterfly_1596();
void Butterfly_1597();
void WEIGHTED_ROUND_ROBIN_Joiner_1595();
void Post_CollapsedDataParallel_2_1407();
void Pre_CollapsedDataParallel_1_1409();
void WEIGHTED_ROUND_ROBIN_Splitter_1598();
void Butterfly_1600();
void Butterfly_1601();
void WEIGHTED_ROUND_ROBIN_Joiner_1599();
void Post_CollapsedDataParallel_2_1410();
void Pre_CollapsedDataParallel_1_1412();
void WEIGHTED_ROUND_ROBIN_Splitter_1602();
void Butterfly_1604();
void Butterfly_1605();
void WEIGHTED_ROUND_ROBIN_Joiner_1603();
void Post_CollapsedDataParallel_2_1413();
void WEIGHTED_ROUND_ROBIN_Joiner_1503();
void WEIGHTED_ROUND_ROBIN_Joiner_1504();
void WEIGHTED_ROUND_ROBIN_Splitter_1505();
void WEIGHTED_ROUND_ROBIN_Splitter_1506();
void Butterfly_1134();
void Butterfly_1135();
void Butterfly_1136();
void Butterfly_1137();
void Butterfly_1138();
void Butterfly_1139();
void Butterfly_1140();
void Butterfly_1141();
void WEIGHTED_ROUND_ROBIN_Joiner_1507();
void WEIGHTED_ROUND_ROBIN_Splitter_1508();
void Butterfly_1142();
void Butterfly_1143();
void Butterfly_1144();
void Butterfly_1145();
void Butterfly_1146();
void Butterfly_1147();
void Butterfly_1148();
void Butterfly_1149();
void WEIGHTED_ROUND_ROBIN_Joiner_1509();
void WEIGHTED_ROUND_ROBIN_Joiner_1510();
int BitReverse_1150_bitrev(int inp, int numbits);
void BitReverse(buffer_float_t *chanin, buffer_float_t *chanout);
void BitReverse_1150();
void FloatPrinter(buffer_float_t *chanin);
void FloatPrinter_1151();

#ifdef __cplusplus
}
#endif
#endif
