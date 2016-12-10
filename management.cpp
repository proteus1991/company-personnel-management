#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<windows.h>
#include<iomanip.h>
const int Maxr=100; 
class people                                              //人员基类
{
protected:
	int number;                                           //编号
	char name[20];                                        //姓名
	char sex[4];                                          //性别
	int age;                                              //年龄
public:
	void show()
{
	cout<<"编号"<<setw(10)<<"姓名"<<setw(10)<<"性别"<<setw(10)<<"年龄"<<endl;
	cout<<number<<setw(10)<<name<<setw(10)<<sex<<setw(10)<<age<<endl;
}
	void set()
	{
      cout<<"请输入编号："<<endl;
	  cin>>number;
	  cout<<"请输入姓名:"<<endl;
	  cin>>name;
      cout<<"请输入性别:"<<endl;
      cin>>sex;
	  cout<<"请输入年龄:"<<endl;
	  cin>>age;
	}
	char *getname() {return name;}                          //名字
    int getno()  {return number;}                           //编号 
    int getage() {return age;}                              //年龄
    char* getsex(){return sex; }                            //性别
	void ren(int n)  {cout<<n<<endl;}
   void add(int n,char *na,int ag,char *se)
	{
		number=n;
		age=ag;
		strcpy(name,na);
		strcpy(sex,se);
	}
};

class student:public people
{
private:
	int grade;
	int sushe;
public:
	void set3()
	{
		set();
		cout<<"请输入班级:"<<endl;
		cin>>grade;
		cout<<"请输入宿舍:"<<endl;
		cin>>sushe;
	}
	void show3()
	{
		show();
		cout<<"班级"<<setw(10)<<"宿舍"<<endl;
		cout<<grade<<setw(10)<<sushe<<endl;
	}
	void setgr(int gr)
	{ grade=gr;}
	void setsu(int su)
	{ sushe=su;}
	int getgr(){return grade;}                                       //班级
	int getsu(){return sushe;}                                       //宿舍
	void add3(int n,char *na,int ag,char *se,int gr,int su)
	{
		add( n,na,ag,se);
		grade=gr;
		sushe=su;
	}
};
class studentbase
{
private:
	int top;
	student read[Maxr];
public:
	studentbase()                                                   //将学生信息从student.txt读取到read[]中
	{
		student s;
		top=-1;
		fstream file("student.txt",ios::in);
		while(1)
		{
			file.read((char*)&s,sizeof(s));
			if(!file)
				break;
			top++;
			read[top]=s;
		}
		file.close();
	}
     void delnu(int n)                                              //按编号删除
	 {
		 int i,y=0;   char x;
         for ( i=0;i<=top;i++) 
		 {   
			 if (read[i].getno()==n)
			 { 
				 cout<<"该学生情况："<<endl;
                 cout<<setw(10)<<read[i].getno()<<setw(10)<<read[i].getname()<<setw(10)<<read[i].getage()<<setw(10)<<read[i].getsex()<<setw(10)<<read[i].getgr()<<setw(10)<<read[i].getsu()<<endl;  
                 cout<<"是否确认删除？（Y/N）"<<endl;
                 cin>>x;   
                   if(x=='Y'||x=='y')
				   {
					   y++;  
					   for(;i<=top-1;i++) read[i]=read[i+1];
                       top--;                                   
				   }
			 }
		 }
            if(y==0)
			{ 
				cout<<"未删除该学生！"<<endl;
			}
               else
			   { 
				cout<<"删除后的信息为："<<endl;
	            for (int i=0;i<=top;i++) 
                 read[i].show3(); 
			   }
	 }
	
       void delname(char*na)                                       //按姓名删除
	   {
		   int i,y=0;     
		   char x;
           for ( i=0;i<=top;i++) 
		   {
			   if(strcmp(read[i].getname(),na)==0)
                 cout<<setw(10)<<read[i].getno()<<setw(10)<<read[i].getname()<<setw(10)<<read[i].getage()<<setw(10)<<read[i].getsex()<<setw(10)<<read[i].getgr()<<setw(10)<<read[i].getsu()<<endl;  
                 cout<<"是否确认删除？（Y/N）"<<endl;
                 cin>>x;   
                   if(x=='Y'||x=='y')
				   {
					   y++;  
					   for(;i<=top-1;i++) read[i]=read[i+1];
                       top--;                                      //每删除一个减少一个
				   }
			 }
            if(y==0)
			{ 
				cout<<"未删除该学生！"<<endl;
			}
               else
			   { 
				 cout<<"删除后的信息为："<<endl;
	             for (int i=0;i<=top;i++) 
                  read[i].show3(); 
			   }
	 }
      void clear()   
	  { top=-1; }                                                 
      int add3(int n,char *na,int ag,char *se ,int gr,int su)        
	  { 
		  student *p=query(n); 
           if (p==NULL)                                             //不存在编号是n的学生，执行增加
		   {  
			   top++;  
			   read[top].add3(n,na,ag,se,gr,su); 
               return 1; 
		   }   
               return 0;  
	  }
       student *query(int n)                                        //判断是否存在编号是n的学生
	   {
		   for (int i=0;i<=top;i++) 
              if(read[i].getno()==n)    
             return &read[i]; 
              return NULL; 
	   } 
       student *query1(char *na)                                   //判断将要增加的姓名是否存在
	   { 
		   for (int i=0;i<=top;i++) 
           if(strcmp(read[i].getname(),na)==0 )   
			return &read[i]; 
            return NULL; 
	   } 
     void disp()                                                   //学生信息显示 
	 { 
		 for (int i=0;i<=top;i++) 
          read[i].show3(); 
	 } 
     void data();                                                  //声明学生数据维护函数
     ~studentbase()                                                //将read[]中的信息读入到student.txt中 
	 { 
		 fstream file("student.txt",ios::out); 
         for (int i=0;i<=top;i++) 
         file.write((char*)&read[i],sizeof(read[i])); 
         file.close();
	 } 
}; 
      void studentbase::data()                                       //定义学生维护 
	  { 
		  int choice=1;    
		  int b=1;                                                   //标记变量
          char x; 
		  int nan=0;                                                 //男学生
          int nv=0;                                                  //女学生 
          char name[20];                                             //姓名
          int number;                                                //编号    
          int age;                                                   //年龄
		  char sex[4];                                               //性别
          int gr;                                                    //班级
		  int su;                                                    //宿舍
          student *r;
          while (choice!=0) 
		  {
	         cout<<setw(15)<<"1：新增"<<endl;
			 cout<<setw(15)<<"2：更改"<<endl; 
			 cout<<setw(15)<<"3：删除"<<endl; 
			 cout<<setw(15)<<"4：查找"<<endl; 
		     cout<<setw(15)<<"5：显示"<<endl; 
			 cout<<setw(15)<<"6：全删"<<endl;  
			 cout<<setw(15)<<"0：退出=>";  
             cin>>choice; 
            switch (choice) 
			{ 
			   case 1:                                                //新增
            
               system("cls");                                         //清屏
               cout<<"输入学生编号："; 
			   cin>>number; 
               cout<<"输入学生姓名：";
			   cin>>name;
               cout<<"输入学生年龄: "; 
			   cin>>age;
               cout<<"输入学生性别（m或f）：";
			   cin>>sex;
              if(strcmp("m",sex)!=0&&strcmp("f",sex)!=0)
			  {
				  while(b)
				  {
					  cout<<"输入性别有误，请重新输入："<<endl;  
					  cin>>sex;
                      if(strcmp("m",sex)==0||strcmp("f",sex)==0)
                       b=0; 
				  }
			  }   
               if(strcmp("m",sex)==0)
			   {nan++;}                                                 //统计男女学生的人数
                 else       
				 {nv++;}
                cout<<"输入学生所在班级："; 
			    cin>>gr;
                cout<<"输入学生所在宿舍:";  
			    cin>>su; 
                add3(number,name,age,sex,gr,su);
			    break; 
                case 2:                                                  //根据查询结果更改
               
                 system("cls");
			     cout<<" 按编号更改1"<<endl;
			     cout<<" 按姓名更改2"<<endl;
			     cout<<" 返回 0"<<endl;
			     cin>>b;
                 while(b)
				 {
				   switch(b)
				  {
				     case 1:
                     cout<<"输入学生编号：";
					 cin>>number; 
                     r=query(number); 
                     if (r==NULL) 
					{ cout<<"该学生不存在"<<endl; break; } 
						r->show3();
                      cout<<"是否确认更改所在班级？（Y/N）"<<endl;
                       cin>>x;
                     if(x=='Y'||x=='y')
					 {
						 cout<<"输入新的班级："<<endl;  
					     cin>>gr;       
						 r->setgr(gr);
                        add3(number,name,age,sex,gr,su);
					 }
                      cout<<"是否确认更改宿舍？（Y/N）"<<endl;
					  cin>>x;
                      if(x=='Y'||x=='y')
					  { 
						  cout<<"请输入新的宿舍"<<endl; 
                           cin>>su;          
						   r->setsu(su); 
						   add3(number,name,age,sex,gr,su);
					  }
                        r->show3();   break;
                      case 2:
                       cout<<"输入学生姓名："; cin>>name; 
                       r=query1(name); 
                        if (r==NULL) 
						{cout<<"该学生不存在"<<endl; break; } 
                         r->show3();
                         cout<<"是否确认更改班级？（Y/N）"<<endl;    cin>>x;
                          if(x=='Y'||x=='y')
						  { cout<<"输入新的宿舍："<<endl; 
                             cin>>gr; r->setgr(gr);
							 add3(number,name,age,sex,gr,su);
						  }
                         cout<<"是否确认更改宿舍？（Y/N）"<<endl;  cin>>x;
                           if(x=='Y'||x=='y')
						   { cout<<"请输入新的宿舍"<<endl; 
                              cin>>su; r->setsu(su);
							  add3(number,name,age,sex,gr,su);
						   }
                            r->show3();  break;
                       case 3:break;
				   }  
				   break;
				 }  
				 break;
                case 3:                                                       //删除
                
                 system("cls");
                 cout<<" 按编号删除 1"<<endl;
			     cout<<" 按姓名删除 2"<<endl;
			     cout<<" 返回 0"<<endl;
                 cin>>b;
                while(b!=0)
				{
					switch(b)
					{
					 case 1: 
                        cout<<"输入学生编号："; 
			            cin>>number;
                        r=query(number); 
                        if (r==NULL) 
						{cout<<"该学生不存在"<<endl; break; } 
                         delnu(number); b=0;   break;
	                  case 2:
                      cout<<"输入学生姓名："<<endl;
					  cin>>name;
                      r=query1(name); 
                       if (r==NULL) 
					   {cout<<"该学生不存在"<<endl; break; } 
	                   delname(name);b=0;  break;
	                  case 3:break;
					}  
					break; 
				} 
				break;
                case 4:                                                      //查找
               
                system("cls");
				 cout<<" 按编号查找 1"<<endl;
			     cout<<" 按姓名查找 2"<<endl;
			     cout<<" 返回 0"<<endl;
                 cin>>b;
                 while(b!=0)
				 { 
					 switch(b) 
					 {
					   case 1: 
                         cout<<"输入学生编号："; cin>>number; 
                         r=query(number); 
                         if (r==NULL) 
						 { cout<<"该学生不存在"<<endl; break; } 
                            r->show3();  break;
                       case 2:
                          cout<<"输入学生姓名 :";cin>>name;
                           r=query1(name);
                           if (r==NULL) 
						   { cout<<"该学生不存在"<<endl; break; } 
                             r->show3();  break; 
					   case 3:         break;
					 }
					 break;
				 }
				 break;
                 case 5:                                                        //显示信息
               
                 system("cls");
                  disp();   break; 
                 case 6:                                                        
               
                  system("cls");   clear();     break;
               
             }
          }
}

class teacher:public people
{
private:
	char zhicheng[20];
	int  time;
	char project[20];
public:
	void set2()
	{
		set();
		cout<<"请输入职称:"<<endl;
        cin>>zhicheng;
        cout<<"请输入任职时间:"<<endl;
		cin>>time;
	    cout<<"请输入专业:"<<endl;
		cin>>project;
	}
	char *getzhi(){return zhicheng;}                                          //职称
	int  gettime(){return time;}                                              //任职时间
	char *getpro(){return project;}                                           //专业
	void setzhi(char zhi[])                                                   //设置职称
	{
		strcpy(zhicheng,zhi);
	}
     void settime(int t)                                                      //设置任职时间
	 {
	      time=t;
	 }
     void setpro(char pro[])                                                  //设置专业
	 {
	      strcpy(project,pro);
	 }
	void show2()
	{
		show();
		cout<<"职称"<<setw(10)<<"任职时间"<<setw(10)<<"专业"<<endl;
		cout<<zhicheng<<setw(10)<<time<<setw(10)<<project<<endl;
	}
	void add2(int n,char *na,int ag,char *se,char *zhi,int ti,char *pro)
	{
		add( n, na, ag, se);
		strcpy(zhicheng,zhi);
		strcpy(project,pro);
		time=ti;
	}

};
class teacherbase
{
private:
	int top;
	teacher read[Maxr];
public:
	teacherbase()                                                   //将职工信息从teacher.txt读取到read[]中
	{
		teacher t;
		top=-1;
		fstream file("teacher.txt",ios::in);
		while(1)
		{
			file.read((char*)&t,sizeof(t));
			if(!file)
				break;
			top++;
			read[top]=t;
		}
		file.close();
	}
     void delnu(int n)                                                       //按编号删除
	 {
		 int i,y=0;   char x;
         for ( i=0;i<=top;i++) 
		 {   
			 if (read[i].getno()==n)
			 { 
				 cout<<"该教师情况："<<endl;
                 read[i].show2();
			 }
                 cout<<"是否确认删除？（Y/N）"<<endl;
                 cin>>x;   
                   if(x=='Y'||x=='y')
				   {
					   y++;  
					   for(;i<=top-1;i++) read[i]=read[i+1];
                       top--;                                           //每删除一个对象总是减少一个
				   }
			 
		 }
            if(y==0)
			{ 
				cout<<"未删除该教师！"<<endl;
			}
               else
			   { 
				cout<<"删除后的信息为："<<endl;
	            for (int i=0;i<=top;i++) 
                 read[i].show2(); 
			   }
	 }
	
       void delname(char*na)                                                   //按姓名删除
	   {
		   int i,y=0;     
		   char x;
           for ( i=0;i<=top;i++) 
		   {
			   if(strcmp(read[i].getname(),na)==0)
				 cout<<setw(10)<<"编号"<<setw(10)<<"姓名"<<setw(10)<<"年龄"<<setw(10)<<"性别"<<setw(10)<<"系部"<<setw(10)<<"职称"<<endl; 
                 cout<<setw(10)<<read[i].getno()<<setw(10)<<read[i].getname()<<setw(10)<<read[i].getage()<<setw(10)<<read[i].getsex()<<setw(10)
					 <<read[i].gettime()<<setw(10)<<read[i].getzhi()<<setw(10)<<read[i].getpro()<<endl;  
                 cout<<"是否确认删除？（Y/N）"<<endl;
                 cin>>x;   
                   if(x=='Y'||x=='y')
				   {
					   y++;  
					   for(;i<=top-1;i++) read[i]=read[i+1];
                       top--;                                               //每删除一个对象总是减少一个
				   }
			 }
            if(y==0)
			{ 
				cout<<"未删除该教师！"<<endl;
			}
               else
			   { 
				 cout<<"删除后的信息为："<<endl;
	             for (int i=0;i<=top;i++) 
                  read[i].show2(); 
			   }
	 }
      void clear()   
	  { top=-1; }                                                                   
      int add2 (int n,char *na,int ag,char *se ,char *zhi,int ti,char *pro)         //增加教师
	  {
		  teacher *p=query(n); 
           if (p==NULL)                                                  //不存在编号是n的教师，执行增加
		   {  
			   top++;  
			   read[top].add2(n,na,ag,se,zhi,ti,pro); 
               return 1; 
		   }   
               return 0;  
	  }
       teacher *query(int n)                                             //判断是否存在编号是n的教师
	   {
		   for (int i=0;i<=top;i++) 
              if(read[i].getno()==n)    
             return &read[i]; 
              return NULL; 
	   } 
       teacher *query1(char *na)                                          //判断将要增加的姓名是否存在
	   { 
		   for (int i=0;i<=top;i++) 
           if(strcmp(read[i].getname(),na)==0 )   
			return &read[i]; 
            return NULL; 
	   } 
     void disp()                                                              //教师信息显示 
	 { 
		 for (int i=0;i<=top;i++) 
          read[i].show2(); 
	 } 
     void data();                                                           //声明教师数据维护函数
     ~teacherbase()                                                         //将read[]中的信息读入到teacher.txt中 
	 { 
		 fstream file("teacher.txt",ios::out); 
         for (int i=0;i<=top;i++) 
         file.write((char*)&read[i],sizeof(read[i])); 
         file.close();
	 } 
}; 
      void teacherbase::data()                                                  //定义教师维护 
	  { 
		  int choice=1;   
		  int b=1;                                                              //标记变量
          char x; 
		  int nan=0;                                                            //男教师
          int nv=0;                                                             //女教师 
          char name[20];                                                        //姓名
          int number;                                                           //编号    
          int age;                                                              //年龄
          char zhi[20];                                                         //职称   
          char sex[4];                                                          //性别
          char pro[20];                                                         //专业
		  int ti;                                                               //时间
          teacher *r;
          while (choice!=0) 
		  {
	         cout<<setw(15)<<"1：新增"<<endl;
			 cout<<setw(15)<<"2：更改"<<endl; 
			 cout<<setw(15)<<"3：删除"<<endl; 
			 cout<<setw(15)<<"4：查找"<<endl; 
		     cout<<setw(15)<<"5：显示"<<endl; 
			 cout<<setw(15)<<"6：全删"<<endl;  
			 cout<<setw(15)<<"0：退出=>";  
             cin>>choice; 
            switch (choice) 
			{ 
			   case 1:                                                           //新增
              
               system("cls");                                                    //清屏
               cout<<"输入教师编号："; 
			   cin>>number; 
               cout<<"输入教师姓名：";
			   cin>>name;
               cout<<"输入教师年龄: "; 
			   cin>>age;
               cout<<"输入教师性别（m或f）：";
			   cin>>sex;
              if(strcmp("m",sex)!=0&&strcmp("f",sex)!=0)
			  {
				  while(b)
				  {
					  cout<<"输入性别有误，请重新输入："<<endl;  
					  cin>>sex;
                      if(strcmp("m",sex)==0||strcmp("f",sex)==0)
                       b=0; 
				  }
			  }   
               if(strcmp("m",sex)==0)
			   {nan++;}                                                      //统计男女教师的人数
                 else       
				 {nv++;}
                cout<<"输入教师所在专业："; 
			    cin>>pro;
                cout<<"输入教师的职称:";  
			    cin>>zhi; 
				cout<<"输入教师的任职时间：";
				cin>>ti;
                add2(number,name,age,sex,zhi,ti,pro);
			    break; 
                case 2:                                                        //根据查询结果更改
                
                 system("cls");
			     cout<<" 按编号更改1"<<endl;
			     cout<<" 按姓名更改2"<<endl;
			     cout<<" 返回 0"<<endl;
			     cin>>b;
                 while(b)
				 {
				   switch(b)
				  {
				     case 1:
                     cout<<"输入教师编号：";
					 cin>>number; 
                     r=query(number); 
                     if (r==NULL) 
					{ cout<<"该教师不存在"<<endl; break; } 
						r->show2();
                      cout<<"是否确认更改职称？（Y/N）"<<endl;
                       cin>>x;
                     if(x=='Y'||x=='y')
					 {
						 cout<<"输入新的职称："<<endl;  
					     cin>>zhi;       
						 r->setzhi(zhi);
                        add2(number,name,age,sex,zhi,ti,pro);
					 }
                      cout<<"是否确认更改任职时间？（Y/N）"<<endl;
					  cin>>x;
                      if(x=='Y'||x=='y')
					  { 
						  cout<<"请输入新的任职时间"<<endl; 
                           cin>>ti;          
						   r->settime(ti); 
						   add2(number,name,age,sex,zhi,ti,pro);
					  }
					  cout<<"是否确认更改专业？（Y/N）"<<endl;
					  cin>>x;
                      if(x=='Y'||x=='y')
					  { 
						  cout<<"请输入新的专业"<<endl; 
                           cin>>pro;          
						   r->setpro(pro); 
						   add2(number,name,age,sex,zhi,ti,pro);
					  }
                        r->show2();   break;

                      case 2:
                       cout<<"输入教师姓名："; cin>>name; 
                       r=query1(name); 
                        if (r==NULL) 
						{cout<<"该教师不存在"<<endl; break; } 
                         r->show2();
						 cout<<"是否确认更改职称？（Y/N）"<<endl;
                         cin>>x;
                         if(x=='Y'||x=='y')
						 {
						   cout<<"输入新的职称："<<endl;  
					       cin>>zhi;       
						   r->setzhi(zhi);
                           add2(number,name,age,sex,zhi,ti,pro);
						 }
                         cout<<"是否确认更改任职时间？（Y/N）"<<endl;
					     cin>>x;
                        if(x=='Y'||x=='y')
						{ 
						   cout<<"请输入新的任职时间"<<endl; 
                           cin>>ti;          
						   r->settime(ti); 
						   add2(number,name,age,sex,zhi,ti,pro);
						}
					    cout<<"是否确认更改专业？（Y/N）"<<endl;
					    cin>>x;
                        if(x=='Y'||x=='y')
						{ 
						   cout<<"请输入新的专业"<<endl; 
                           cin>>pro;          
						   r->setpro(pro); 
						   add2(number,name,age,sex,zhi,ti,pro);
						}
                            r->show2();  break;
                       case 3:break;
				   }  
				   break;
				 }  
				 break;
                case 3:                                                        //删除
               
                 system("cls");
                 cout<<" 按编号删除 1"<<endl;
			     cout<<" 按姓名删除 2"<<endl;
			     cout<<" 返回 0"<<endl;
                 cin>>b;
                while(b!=0)
				{
					switch(b)
					{
					 case 1: 
                        cout<<"输入教师编号："; 
			            cin>>number;
                        r=query(number); 
                        if (r==NULL) 
						{cout<<"该教师不存在"<<endl; break; } 
                         delnu(number); b=0;   break;
	                  case 2:
                      cout<<"输入教师姓名："<<endl;
					  cin>>name;
                      r=query1(name); 
                       if (r==NULL) 
					   {cout<<"该教师不存在"<<endl; break; } 
	                   delname(name);b=0;  break;
	                  case 3:break;
					}  
					break; 
				} 
				break;
                case 4:                                                      //查找
              
                system("cls");
				 cout<<" 按编号查找 1"<<endl;
			     cout<<" 按姓名查找 2"<<endl;
			     cout<<" 返回 0"<<endl;
                 cin>>b;
                 while(b!=0)
				 { 
					 switch(b) 
					 {
					   case 1: 
                         cout<<"输入教师编号："; cin>>number; 
                         r=query(number); 
                         if (r==NULL) 
						 { cout<<"该教师不存在"<<endl; break; } 
                            r->show2();  break;
                       case 2:
                          cout<<"输入教师的姓名 :";cin>>name;
                           r=query1(name);
                           if (r==NULL) 
						   { cout<<"该教师不存在"<<endl; break; } 
                             r->show2();  break; 
					   case 3:         break;
					 }
					 break;
				 }
				 break;
                 case 5:                                                            //显示信息
                 
                 system("cls");
                  disp();   break; 
                 case 6:                                                            
               
                  system("cls");   clear();     break;
          
             }
          }
}

class  leader: public people                                                        //职工类
{
private:
	char bumen[20];
	char zhineng[20];
public:
	void set1()
	{
		set();
		cout<<"请输入任职部门:"<<endl;
		cin>>bumen;
     	cout<<"请输入职能:"<<endl;
		cin>>zhineng;
	}
	void setbu(char bu[])
	{
		strcpy(bumen,bu);
	}
	void setzhi(char zhi[])
	{
		strcpy(zhineng,zhi);
	}
	void show1()
	{
        show();
		cout<<"部门"<<setw(10)<<"职能"<<endl;
		cout<<bumen<<setw(10)<<zhineng<<endl;
	}
	void add1(int n,char *na,int ag,char *se,char *bu,char *zhi)
	{
		add( n, na, ag, se);
		strcpy(bumen,bu);
		strcpy(zhineng,zhi);
	}
	char *getbu(){return bumen;}                                 //部门
	char *getzhi(){return zhineng;}                              //职能
};
class staff
{
private:
	int top;
	leader read[Maxr];
public:
	staff()                                                   //将职工信息从staff.txt读取到read[]中
	{
		leader l;
		top=-1;
		fstream file("staff.txt",ios::in);
		while(1)
		{
			file.read((char*)&l,sizeof(l));
			if(!file)
				break;
			top++;
			read[top]=l;
		}
		file.close();
	}
     void delnu(int n)                                                  //按编号删除
	 {
		 int i,y=0;   char x;
         for ( i=0;i<=top;i++) 
		 {   
			 if (read[i].getno()==n)
			 { 
				 cout<<"该职工情况："<<endl;
                 cout<<setw(10)<<"编号"<<setw(10)<<"姓名"<<setw(10)<<"年龄"<<setw(10)<<"性别"<<setw(10)<<"部门"<<setw(10)<<"职能"<<endl; 
cout<<setw(10)<<read[i].getno()<<setw(10)<<read[i].getname()<<setw(10)<<read[i].getage()<<setw(10)<<read[i].getsex()<<setw(10)<<read[i].getbu()<<setw(10)<<read[i].getzhi()<<endl;  
                 cout<<"是否确认删除？（Y/N）"<<endl;
                 cin>>x;   
                   if(x=='Y'||x=='y')
				   {
					   y++;  
					   for(;i<=top-1;i++) read[i]=read[i+1];
                       top--;                                       //每删除一个对总是减少一个
				   }
			 }
		 }
            if(y==0)
			{ 
				cout<<"未删除该职工"<<endl;
			}
               else
			   { 
				cout<<"删除后的信息为："<<endl;
	            for (int i=0;i<=top;i++) 
                 read[i].show1(); 
			   }
	 }
	      void delname(char*na)                                        //按姓名删除
	   {
		   int i,y=0;     
		   char x;
           for ( i=0;i<=top;i++) 
		   {
			   if(strcmp(read[i].getname(),na)==0)
				 cout<<setw(10)<<"编号"<<setw(10)<<"姓名"<<setw(10)<<"年龄"<<setw(10)<<"性别"<<setw(10)<<"部门"<<setw(10)<<"职能"<<endl; 
                 cout<<setw(10)<<read[i].getno()<<setw(10)<<read[i].getname()<<setw(10)<<read[i].getage()<<setw(10)<<read[i].getsex()<<setw(10)<<read[i].getbu()<<setw(10)<<read[i].getzhi()<<endl;  
                 cout<<"是否确认删除？（Y/N）"<<endl;
                 cin>>x;   
                   if(x=='Y'||x=='y')
				   {
					   y++;  
					   for(;i<=top-1;i++) read[i]=read[i+1];
                       top--;                                          //每删除一个对总是减少一个
				   }
			 }
            if(y==0)
			{ 
				cout<<"未删除该职工！"<<endl;
			}
               else
			   { 
				 cout<<"删除后的信息为："<<endl;
	             for (int i=0;i<=top;i++) 
                  read[i].show1(); 
			   }
	 }
      void clear()   
	  { top=-1; }                                                          
      int add (int n,char *na,int ag,char *se ,char *bu,char *zhi)         //增加职工 
	  { 
		  leader *p=query(n); 
           if (p==NULL)                                                    //不存在编号是n的职工，执行增加
		   {  
			   top++;  
			   read[top].add1(n,na,ag,se,bu,zhi); 
               return 1; 
		   }   
               return 0;  
	  }
       leader *query(int n)                                                 //判断是否存在编号是n的职工
	   {
		   for (int i=0;i<=top;i++) 
              if(read[i].getno()==n)    
             return &read[i]; 
              return NULL; 
	   } 
       leader *query1(char *na)                                             //判断将要增加的姓名是否存在
	   { 
		   for (int i=0;i<=top;i++) 
           if(strcmp(read[i].getname(),na)==0 )   
			return &read[i]; 
            return NULL; 
	   } 
     void disp()                                                            //职工信息显示 
	 { 
		 for (int i=0;i<=top;i++) 
          read[i].show1(); 
	 } 
     void data();                                                           //声明职工数据维护函数
     ~staff()                                                               //将read[]中的信息读如到staff.txt中 
	 { 
		 fstream file("staff.txt",ios::out); 
         for (int i=0;i<=top;i++) 
         file.write((char*)&read[i],sizeof(read[i])); 
         file.close();
	 } 
}; 
      void staff::data()                                                   //定义职工维护 
	  { 
		  int choice=1;    
		  int b=1;                                                         //标记变量
          char x; 
		  int nan=0;                                                       //男职工
          int nv=0;                                                        //女职工  
          char name[20];                                                   //姓名
          int number;                                                      //编号    
          int age;                                                         //年龄
          char zhi[20];                                                    //职能   
          char sex[4];                                                     //性别
          char bu[20];                                                     //部门  
          leader *r;
          while (choice!=0) 
		  {
	         cout<<setw(15)<<"1：新增"<<endl;
			 cout<<setw(15)<<"2：更改"<<endl; 
			 cout<<setw(15)<<"3：删除"<<endl; 
			 cout<<setw(15)<<"4：查找"<<endl; 
		     cout<<setw(15)<<"5：显示"<<endl; 
			 cout<<setw(15)<<"6：全删"<<endl;  
			 cout<<setw(15)<<"0：退出=>";  
             cin>>choice; 
            switch (choice) 
			{ 
			   case 1:                                                      //新增
               
               system("cls");                                               //清屏
               cout<<"输入职工编号："; 
			   cin>>number; 
               cout<<"输入职工姓名：";
			   cin>>name;
               cout<<"输入职工年龄: "; 
			   cin>>age;
               cout<<"输入职工性别（m or f）：";cin>>sex;
              if(strcmp("m",sex)!=0&&strcmp("f",sex)!=0)
			  {
				  while(b)
				  {
					  cout<<"输入性别有误，请重新输入："<<endl;  
					  cin>>sex;
                      if(strcmp("m",sex)==0||strcmp("f",sex)==0)
                       b=0; 
				  }
			  }   
               if(strcmp("m",sex)==0)
			   {nan++;}                                                     //统计男女职工的人数
                 else       
				 {nv++;}
                cout<<"输入职工所在部门："; 
			    cin>>bu;
                cout<<"输入职工的职能:";  
			    cin>>zhi; 
                add(number,name,age,sex,bu,zhi);
			    break; 
                case 2:                                                     //根据查询结果更改
                 
                 system("cls");
			     cout<<" 按编号更改1"<<endl;
			     cout<<" 按姓名更改2"<<endl;
			     cout<<" 返回 0"<<endl;
			     cin>>b;
                 while(b)
				 {
				   switch(b)
				  {
				     case 1:
                     cout<<"输入职工编号：";
					 cin>>number; 
                     r=query(number); 
                     if (r==NULL) 
					{ cout<<"该职工不存在"<<endl; break; } 
						r->show1();
                      cout<<"是否确认更改任职部门？（Y/N）"<<endl;
                       cin>>x;
                     if(x=='Y'||x=='y')
					 {
						 cout<<"输入新的任职部门："<<endl;  
					     cin>>bu;       
						 r->setbu(bu);
                        add(number,name,age,sex,bu,zhi);
					 }
                      cout<<"是否确认更改职能？（Y/N）"<<endl;
					  cin>>x;
                      if(x=='Y'||x=='y')
					  { 
						  cout<<"请输入新的职能"<<endl; 
                           cin>>zhi;          
						   r->setzhi(zhi); 
						   add(number,name,age,sex,bu,zhi);
					  }
                        r->show1();   break;
                      case 2:
                       cout<<"输入职工姓名："; cin>>name; 
                       r=query1(name); 
                        if (r==NULL) 
						{cout<<"该职工不存在"<<endl; break; } 
                         r->show1();
                         cout<<"是否确认更改任职部门？（Y/N）"<<endl;    cin>>x;
                          if(x=='Y'||x=='y')
						  { cout<<"输入新的任职部门："<<endl; 
                             cin>>bu; r->setbu(bu);
							 add(number,name,age,sex,bu,zhi);
						  }
                         cout<<"是否确认更改职能？（Y/N）"<<endl;  cin>>x;
                           if(x=='Y'||x=='y')
						   { cout<<"请输入新的职能"<<endl; 
                              cin>>zhi; r->setzhi(zhi);
							  add(number,name,age,sex,bu,zhi);
						   }
                            r->show1();  break;
                       case 3:break;
				   }  
				   break;
				 }  
				 break;
                case 3:                                                       //删除信息
               
                 system("cls");
                 cout<<" 按编号删除 1"<<endl;
			     cout<<" 按姓名删除 2"<<endl;
			     cout<<" 返回 0"<<endl;
                 cin>>b;
                while(b!=0)
				{
					switch(b)
					{
					 case 1: 
                        cout<<"输入职工编号："; 
			            cin>>number;
                        r=query(number); 
                        if (r==NULL) 
						{cout<<"该职工不存在"<<endl; break; } 
                         delnu(number); b=0;   break;
	                  case 2:
                      cout<<"输入职工姓名："<<endl;
					  cin>>name;
                      r=query1(name); 
                       if (r==NULL) 
					   {cout<<"该职工不存在"<<endl; break; } 
	                   delname(name);b=0;  break;
	                  case 3:break;
					}  
					break; 
				} 
				break;
                case 4:                                                      //查找信息
               
                system("cls");
				 cout<<" 按编号查找 1"<<endl;
			     cout<<" 按姓名查找 2"<<endl;
			     cout<<" 返回 0"<<endl;
                 cin>>b;
                 while(b!=0)
				 { 
					 switch(b) 
					 {
					   case 1: 
                         cout<<"输入职工编号："; cin>>number; 
                         r=query(number); 
                         if (r==NULL) 
						 { cout<<"该职工不存在"<<endl; break; } 
                            r->show1();  break;
                       case 2:
                          cout<<"输入职工姓名 :";cin>>name;
                           r=query1(name);
                           if (r==NULL) 
						   { cout<<"该职工不存在"<<endl; break; } 
                             r->show1();  break; 
					   case 3:         break;
					 }
					 break;
				 }
				 break;
                 case 5:                                                       //显示信息
                  
                 system("cls");
                  disp();   break; 
                 case 6:                                                       
               
                  system("cls");   clear();     break;
                 
             }
          }
}

int main() 
{ p:
   int choice=1;   
   staff f;
   teacherbase t;   
   studentbase s;
while(choice!=0) 
{ cout<<endl; 
  cout<<endl;   cout<<endl; 
  cout<<setw(20)<<"         欢迎使用西南交大人员管理系统"<<endl; 
  cout<<endl;   cout<<"制作人：刘笑宏 20102889 李亢亢 20102872 刘妍 20100147 "<<endl; 
  cout<<setw(20)<<""<<endl; 
  cout<<setw(20)<<"              请选择您所需的操作\n"; 
  cout<<setw(20)<<"                                                                                "<<endl;
  cout<<setw(20)<<"                1.学生信息管理\n"; 
  cout<<setw(20)<<"                                                                                "<<endl;
  cout<<setw(20)<<"                2.教师信息管理\n";
  cout<<setw(20)<<"                                                                                "<<endl;
  cout<<setw(20)<<"                3.职工信息管理\n";
  cout<<setw(20)<<"                                                                                "<<endl;
  cout<<setw(20)<<"                0.退出信息管理\n"; 
  cout<<setw(20)<<"      welcome to swjtu management system  "<<endl;
  cin>>choice; 
 switch(choice) 
{ case 1:   while(1)
{ cout<<setw(20);   s.data(); goto p; }
  case 2: 
  while(1)
{ cout<<setw(20);   t.data(); goto p;}
  case 3: 
  while(1)
{ cout<<setw(20);   f.data(); goto p;} 
  break;}
}
   return 0;
}
 

