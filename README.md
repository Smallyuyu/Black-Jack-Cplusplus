# Black-Jack-Cplusplus
## 美編：
	gotoxy：清屏、cout

## 繪製：
	printmenu()：輸出選項菜單
	print_card()：輸出閒家的卡牌
	print_dealer_card()：輸出莊家的卡牌

## 玩家資料儲存：
	用物件導向先寫PlayerPoint.cpp、PlayerPoint.h兩個檔案
	變數：
	Live：玩家生命（金錢小於1000即死亡）
	S_live：玩家該局的生命（卡牌點數大於21即死亡）
	Point_sum：所有持有卡牌的點數總和
	Money：目前所持有的金錢
	Bet：該局賭注金額
	Insurance_bet：保險賭注金額
	Double_flag：判斷是否有資格雙倍賭注
	Initial_money：該局開始時的金額
	Surrender_flag：判斷玩家是否投降
	Had_acd：判斷玩家是否有卡牌A
	Arr：儲存所持有的所有卡牌

## 功能：
	Push：推入新的卡牌
	Top：回傳最新拿到的一張卡牌
	Empty：清除所有卡牌
	Bank：加金額
	Point_plus：加總點數和
	Get_size：回傳卡牌張數

## 卡牌對應：
	用一個map來儲存數字與英文符號對應，
	再用另一個map來儲存數字與卡牌大小的對應

## 排名：
	用struct來儲存玩家編號以及最後所剩金額，並排序輸出

