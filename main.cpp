#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<stdio.h>
using namespace std;


int days_order(string d);
int random(int a,int b);


vector<long int>list;

void set_student(){			//this function will add students to the list
	long int new_stu;
	do{	
	
	list.push_back(new_stu);
	cin>>new_stu;
	}while(new_stu!=(-1));

}

void write_stu(){			//this function writes student numbers to the file
	ofstream stu_file;
	stu_file.open("lesson_file.txt",ios::app);
	for(int j=0;j<list.size();j++){
		stu_file<<list.at(j)<<endl;
	}
}

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

friend int find_time_index(vector<time> ti_list,const time& t);
																					// I wrote them as friend so they can have access to private and protected members  
friend class lesson;
};

int find_time_index(vector<time> ti_list,const time& t){		//finds time index in the time array 
	
	for(int w=0;w<36;w++){
		if(ti_list.at(w)=t){
			return w;
		}

}
}


class room{
	int num;
	bool vid_p=0;

	public:
		
		room(int n,bool v){			//constructor
			num=n;
			vid_p=v;
		}
		void room_show(){		//shows the room
			cout<<"room number :"<<num;
		}
		
		friend void make_room(vector<room>,vector<room>);
		
		friend ostream &operator<<(ostream &output,const room &r){		//overloades "<<" operator so we can cout objects of the class
			output <<"room number :"<<r.num<<endl;
			return output;
		}


//		bool* operator [](int index){				//I couldnt find a way to overload [][] operator for my 2d array
//			return array[index];
//			}

};


//int find_time_index(time array[],const time& t);

bool array[5][36];		//time tabel

void reservation(time t1,time t2,room w,int day_number){
	

	vector<time>arr={time(8,0),time(8,15),time(8,30),time(8,45),time(9,0),time(9,15),time(9,30),time(9,45),time(10,0),time(10,15),time(10,30),time(10,45),time(11,0),time(11,15),time(11,30),time(11,45),time(12,0),time(12,15),time(12,30),time(12,45),time(13,0),time(13,15),time(13,30),time(13,45),time(14,0),time(14,15),time(14,30),time(14,45),time(15,0),time(15,15),time(15,30),time(15,45),time(16,0),time(16,15),time(16,30),time(16,45),time(17,0)};
		
	int n1=find_time_index(arr,t1);
	int n2=find_time_index(arr,t2);
	for(n1;n1<=n2;n1++){
		array[day_number][n1]=true;
	}

}


void show_timeline(room d){
	cout<<"this is the timeline of ";
	d.room_show();
	cout<<"\t(0) stands for free times & (1) stands for reserved times ."<<endl;
	
	for(int i=0;i<5;i++)
		for(int j=0;j<36;j++){
			cout<<array[i][j];
			if (j==35)
			{
				cout<<endl;
			}
		}
}



	vector<room>rooms_vp;	//list of rooms with video_projector
	vector<room>rooms_nvp;  //list of rooms with out video_projector

void make_room(vector<room>,vector<room>){

	bool v_d; 
	int x=0;
	int entery;	
	cout<<"you have came to (room) section."<<endl;
do {

	cout<<"do you want video_projector for room number ("<<x<< ") ? enter 1 as YES , 0 as NO and -1 to stop :";
	cin>>entery;
	if(entery==-1) break;
	if(entery==1||entery==0){
		v_d=entery;
	}
	else{
		cout<<"invalid argument!!";
		v_d=0;
	}
	if(v_d==1){
	rooms_vp.push_back(room(x,v_d));	
	}
	else{
	rooms_nvp.push_back(room(x,v_d));
	}
	
	x++;
}while(entery!=(-1));
}



class lesson{
	private:
		string name;
		string teacher_n;
		int period;
		bool need_projector;
		string ID;
		int enetry;
	protected:
		time start;
		time dur;
		string day;
	public:
		
		friend void reservation(time t1(),time t2(),string day);
		
		lesson(string n=" ",string t_n=" ",int p=0,bool n_p=false):name(n),teacher_n(t_n),period(p),need_projector(n_p){};
		void set_lesson(){
			do{

			cout<<"please enter an ID for this lesson :";
			cin>>ID;
			
			cout<<endl<<"enter name of lesson :";
			cin>>name;
			
			cout<<"in which day do you want to perform your class ?";
			do{
				cin>>day;
			}while(days_order(day)==(-1));
			
			
			cout<<"time :"<<endl;
			cout<<"\tstart time :"<<endl;
			start.get_t();
			
			cout<<endl<<"\tduration :"<<endl;
			dur.get_t();

			cout<<endl<<"how many days the term lasts ?";
			cin>>period;
			
			cout<<endl<<"do you want video-projector for this lesson? enter 1 as yes and 0 as no :";
			cin>>need_projector;
			
			bool answer;
			
			if(need_projector){
			cout<<"if you want us to pick a room for this lesson enter 0 if you want to pick it yourself enter 1 :";
			cin>>answer;
			if(answer){
				cout<<"pick a number from left column :"<<endl;
				for(int z=0;z<rooms_vp.size();z++){
					cout<<"("<<z<<"):";
					cout << rooms_vp.at(z);
				}
				int t;
				cin>>t;
				for(int z=0;z<rooms_vp.size();z++){
					if(t==z){
					 reservation(start,start+dur,rooms_vp.at(t),days_order(day));
					 show_timeline(rooms_vp.at(t));
					}
				}
				
			}
			else{
				int r=random(0,rooms_vp.size());
				reservation(start,start+dur,rooms_vp.at(r),days_order(day));
				show_timeline(rooms_vp.at(r));
			}
		}
			else{			
			cout<<"if you want us to pick a room for this lesson enter 0 if you want to pick it yourself enter 1 :";
			cin>>answer;
			if(answer){				
			cout<<"pick a number from left column :"<<endl;
				for(int c=0;c<rooms_nvp.size();c++){
					cout<<"("<<c<<"):";
					cout<<rooms_nvp.at(c);
				}
				int g;
				cin>>g;
				for(int c=0;c<rooms_nvp.size();c++){
					if(g==c){
					 reservation(start,start+dur,rooms_nvp.at(g),days_order(day));
					 show_timeline(rooms_nvp.at(g));
					}
			}
			}
			else{
				int e=random(0,rooms_nvp.size());
				reservation(start,start+dur,rooms_nvp.at(e),days_order(day));
				show_timeline(rooms_nvp.at(e));
			}

			} 
			
			cout<<endl<<"enter teacher name :";
			cin>>teacher_n;
			
			cout<<endl<<"enter the student number of your students : (you should enter numbers in 6 digits and you can stop with entering (-1)) :"<<endl;
			set_student();
			cout<<"do you want to to continue making lessons? eneter (1) as YES and (0) as NO"<<endl;
			cin>>enetry;
		}while(enetry==1);
	}
	
	
		time ret_end(){
			return (start+dur);
			}
		
		
		void write_file(){
			ofstream lesson_file;
			lesson_file.open("lesson_file.txt",ios::app);
			if(lesson_file.is_open()){
			lesson_file<<endl<<"ID :"<<this->ID<<endl<<"Name :"<<this->name<<endl<<"Day :"<<this->day<<endl<<"Time :"<<endl<<"\tstart:"<<endl<<"\t\thour :"<<this->start.hour<<endl<<"\t\tminute :"<<this->start.minute<<endl;
			lesson_file<<"\tend :"<<endl<<"\t\thour :"<<this->ret_end().hour<<endl<<"\t\tminute :"<<this->ret_end().minute;
			lesson_file<<endl<<"video projector :"<<std::boolalpha<<need_projector<<endl;
			write_stu();
			}
			else{
				cout<<"file opening failed!!";
			}
		}

};



int days_order(string d){    				//this function gets the day and sends its index in the week
	
		if(d=="sunday")return 0;
			
		else if(d=="monday")return 1;
			
		else if(d== "tuesday")return 2;
		
		else if (d== "wednesday")return 3;
			
		else if (d=="thursday")return 4;
		
		else {
		cout<<"invalid argument!! you should choose a day between (sunday),(monday),(tuesday),(wednesday),(thursday)"<<endl;
		return -1;
		}
}









int random(int a,int b){
	int i = rand()%(b-a+1)+a;
	return i;
}


int main(){	
make_room(rooms_vp,rooms_nvp);
lesson l;
l.set_lesson();
l.write_file();


}


