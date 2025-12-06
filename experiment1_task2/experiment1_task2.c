#include<stdio.h>
#include<stdbool.h>

struct date{
	int year;
	int month;
	int day; 
};

//判断是否为闰年 
bool isleap(int year);

//判断日期是否有效 
bool isvalid(struct date *d1, struct date *d2);

//计算相差月份包含的天数 
int calculate_month(int year, int month);

//计算总相差天数 
int calculate_date(struct date *d1, struct date *d2);
 
int main(){
	struct date d1 = {1990,01,01};
	struct date d2;
	
	scanf("%4d-%2d-%2d", &d2.year, &d2.month, &d2.day);
	
	if(!isvalid(&d1, &d2)) {
		printf("Invalid input");
	}else{
		if(calculate_date(&d1, &d2) % 5 <= 3){
			printf("working");
		}else{
			printf("rest");
		}
	}
	
	return 0;
} 

bool isleap(int year){
	bool ret;
	if(year % 400 == 0 || year % 100 != 0 && year % 4 == 0){
		return true;
	}else{
		return false;
	}
}

bool isvalid(struct date *d1, struct date *d2){
	int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(isleap(d2->year)){
		a[1] = 29;
	}
	
	//检查年 
	if(d2->year < d1->year){
		return false;
	}
	//检查月 
	else if(d2->month > 12 || d2->month < 1){
		return false;
	}
	//检查日 
	else if(d2->day < 1 || d2->day > a[d2->month - 1]){
		return false;
	}
	else{
		return true;
	}
}

int calculate_month(int year, int month){
	int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int ret = 0;
	int i;
	//该年是闰年 
	if(isleap(year)){
		a[1] = 29;
		for(i = 0; i < month; i++){
			ret += a[i];
		}
	}
	//该年不是闰年 
	else{
		for(i = 0; i < month; i++){
			ret += a[i];
		}
	}
	return ret;
}


int calculate_date(struct date *d1, struct date *d2){
	int ret = 0;
	int i = 0;
	
	//计算年 
	for(i = d1->year; i < d2->year; i++){
		if(isleap(i)){
			ret += 366;
		}else{
			ret += 365;
		}
	}
	
	//计算月 
	ret += calculate_month(d2->year, d2->month - d1->month);
	
	//计算日
	ret += d2->day - d1->day; 
	
	return ret;
}


