// AUTO GENERATED CODE

#include "VectorTest.hpp"
#include <iostream>

extern VectorTest<int> vectors;
void CasePushSingle();
void CaseMorePushes();
void CasePopSingle();
void CaseInsertSingles();
void CaseInsertRange();
void CaseInsertFill();
void CaseConstructIter();
void CaseConstructBadIter();
void CaseAssignRange();
void CaseAssignFill();
void CaseErase();
void CaseEraseIter();
void CaseResize();
void CaseClear();
void CaseSwap();
void CaseReserveSmall();
void CaseReserveLarge();

int main()
{
	vectors.Run(CasePushSingle, "CasePushSingle");
	vectors.Run(CaseMorePushes, "CaseMorePushes");
	vectors.Run(CasePopSingle, "CasePopSingle");
	vectors.Run(CaseInsertSingles, "CaseInsertSingles");
	vectors.Run(CaseInsertRange, "CaseInsertRange");
	vectors.Run(CaseInsertFill, "CaseInsertFill");
	vectors.Run(CaseConstructIter, "CaseConstructIter");
	vectors.Run(CaseConstructBadIter, "CaseConstructBadIter");
	vectors.Run(CaseAssignRange, "CaseAssignRange");
	vectors.Run(CaseAssignFill, "CaseAssignFill");
	vectors.Run(CaseErase, "CaseErase");
	vectors.Run(CaseEraseIter, "CaseEraseIter");
	vectors.Run(CaseResize, "CaseResize");
	vectors.Run(CaseClear, "CaseClear");
	vectors.Run(CaseSwap, "CaseSwap");
	vectors.Run(CaseReserveSmall, "CaseReserveSmall");
	vectors.Run(CaseReserveLarge, "CaseReserveLarge");
}
