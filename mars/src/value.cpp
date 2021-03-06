/********************************************************************
	----------------------------------------------------------------
    软件许可证 － GPL
	版权所有 (C) 2005-2008 极速人工智能研究
	----------------------------------------------------------------
	这一程序是自由软件，你可以遵照自由软件基金会出版的GNU 通用公共许
	可证条款来修改和重新发布这一程序。或者用许可证的第二版，或者（根
	据你的选择）用任何更新的版本。
    发布这一程序的目的是希望它有用，但没有任何担保。甚至没有适合特定
	目地的隐含的担保。更详细的情况请参阅GNU通用公共许可证。
    你应该已经和程序一起收到一份GNU通用公共许可证的副本（本目录
	GPL.txt文件）。如果还没有，写信给：
    The Free Software Foundation, Inc.,  675  Mass Ave,  Cambridge,
    MA02139,  USA
	----------------------------------------------------------------
	如果你在使用本软件时有什么问题或建议，请用以下地址与我们取得联系：
			http://www.jsmaster.com
	或发信到：
			jschess##163.com
	----------------------------------------------------------------
	本文件用途：	略
	
	  
	本文件编写人：	
				顾剑辉			jschess##163.com
		
	本文件版本：	03
	最后修改于：	2006-1-16
		  
	注：以上E-Mail地址中的##请用@替换，这样做是为了抵制恶意的E-Mail
	地址收集软件。
	----------------------------------------------------------------
	修正历史：
			
		  2006-1		第一版发布
********************************************************************/
#include "value.h"
#include "util.h"

const int MaterialPiece[32]=
{
	0,
	400,400,
	400,400,
	880,880,
	2000,2000,
	960,960,
	90,90,90,90,90,
	0,
	400,400,
	400,400,
	880,880,
	2000,2000,
	960,960,
	90,90,90,90,90
};
const int ValuePiece[32]=
{
ValueKing ,
ValueAdvisor,ValueAdvisor,
ValueBishop ,ValueBishop ,
ValueKnight ,ValueKnight ,
ValueRook  ,ValueRook  ,
ValueCannon ,ValueCannon ,
ValuePawn ,ValuePawn ,ValuePawn ,ValuePawn ,ValuePawn ,
ValueKing ,
ValueAdvisor,ValueAdvisor,
ValueBishop ,ValueBishop ,
ValueKnight ,ValueKnight ,
ValueRook  ,ValueRook  ,
ValueCannon ,ValueCannon ,
ValuePawn ,ValuePawn ,ValuePawn ,ValuePawn ,ValuePawn
};

// value_is_ok()

bool value_is_ok(int value) {

   if (value < -ValueInf || value > +ValueInf) return false;

   return true;
}

// range_is_ok()

bool range_is_ok(int min, int max) {

   if (!value_is_ok(min)) return false;
   if (!value_is_ok(max)) return false;

   if (min >= max) return false; // alpha-beta-like ranges cannot be null

   return true;
}

// value_is_mate()

bool value_is_mate(int value) {

   

   if (value < -ValueEvalInf || value > +ValueEvalInf) return true;

   return false;
}

// value_to_trans()

int value_to_trans(int value, int height) {

   
   ASSERT(height_is_ok(height));

   if (value < -ValueEvalInf) {
      value -= height;
   } else if (value > +ValueEvalInf) {
      value += height;
   }

   

   return value;
}

// value_from_trans()

int value_from_trans(int value, int height) {

   
   ASSERT(height_is_ok(height));

   if (value < -ValueEvalInf) {
      value += height;
   } else if (value > +ValueEvalInf) {
      value -= height;
   }

   

   return value;
}

// value_to_mate()

int value_to_mate(int value) {

   int dist;

   

   if (value < -ValueEvalInf) {

      dist = (ValueMate + value) / 2;
      ASSERT(dist>0);

      return -dist;

   } else if (value > +ValueEvalInf) {

      dist = (ValueMate - value + 1) / 2;
      ASSERT(dist>0);

      return +dist;
   }

   return 0;
}

