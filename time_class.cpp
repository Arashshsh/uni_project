class time{
	unsigned int hour=8;
	unsigned int minute=0;
	bool valid=true;
	
	
	public:
		
	inline void find_val(int h,int m){			//finds if values are valid or not
		if(h>17||m>59||(h==17&&m>0)||(m%15!=0)) {
			valid=false;
			cout<<"invalid value provided for argument!! \nplease try again";
		}

	}
	
	time(int h=8,int m=0){			//constructor
		find_val(h,m);
		if(valid){
		hour=h;
		minute=m;
		}
			
	}
	
	void set_t(){				//this function will check if the time values are valid or not (it will be used for start-end times)
		int h,m;
		cout<<"enter hour :";
		cin>>h;
		cout<<"enter minute :";
		cin>>m;
		find_val(h,m);
		if(valid){
			hour=h;
			minute=m;
		}	
	}
	
	void get_t(){				//this function will not check if the values are valid or not(we mostly use this for durations)
		cout<<"enter hour :";
		cin>>hour;
		cout<<"enter minute :";
		cin>>minute;
	}
	
	void show_t(){				//shows the time
			if(hour<10&&(minute!=0)){
				cout<<"0"<<hour<<":"<<minute;
			}
			else if(hour<10&&(minute==0)){
				cout<<"0"<<hour<<":"<<"00";
			}
			else if(hour>10&&(minute==0)){
				cout<<hour<<":"<<"00";
			}
			else{
				cout<<hour<<":"<<minute;
			}
	}	
	
	time operator -(const time &t){			//overloades the "-" operator for two times
		int dur_h = this->hour-t.hour;
		int dur_m = this->minute-t.minute;
		if(dur_m<0){
			dur_m+=60;
			dur_h--;
		}
		time result(dur_h,dur_m);
		return result;		
	}
	
	
	
	time operator +(const time& t){			//overloades the "+" operator for two times
		int sum_h = this->hour+t.hour;
		int sum_m = this->minute+t.minute;
		if(sum_m>60){
			sum_m=sum_m-60;
			sum_h++;
		}
		if(sum_m==60){
			sum_m=0;
			sum_h++;
		}
		
		time result(sum_h,sum_m);
		return result;
	}


	void operator +(int m){				//overloades the "+" operator for one time and an integer
		if(m%15==0){
			(this->minute)=+m;
		}
		if(minute==60){
			(this->minute)==0;
			(this->hour)--;
		}
	}	
	
	
	bool operator =(const time& t){			//overloades the "=" operator
	if (this->hour==t.hour&&this->minute==t.minute){
		return true;
	}
	else{
		return false;
	}
}


};

