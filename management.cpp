#include<iostream.h>
#include<fstream.h>
#include<string.h>
#include<windows.h>
#include<iomanip.h>
const int Maxr=100; 
class people                                              //��Ա����
{
protected:
	int number;                                           //���
	char name[20];                                        //����
	char sex[4];                                          //�Ա�
	int age;                                              //����
public:
	void show()
{
	cout<<"���"<<setw(10)<<"����"<<setw(10)<<"�Ա�"<<setw(10)<<"����"<<endl;
	cout<<number<<setw(10)<<name<<setw(10)<<sex<<setw(10)<<age<<endl;
}
	void set()
	{
      cout<<"�������ţ�"<<endl;
	  cin>>number;
	  cout<<"����������:"<<endl;
	  cin>>name;
      cout<<"�������Ա�:"<<endl;
      cin>>sex;
	  cout<<"����������:"<<endl;
	  cin>>age;
	}
	char *getname() {return name;}                          //����
    int getno()  {return number;}                           //��� 
    int getage() {return age;}                              //����
    char* getsex(){return sex; }                            //�Ա�
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
		cout<<"������༶:"<<endl;
		cin>>grade;
		cout<<"����������:"<<endl;
		cin>>sushe;
	}
	void show3()
	{
		show();
		cout<<"�༶"<<setw(10)<<"����"<<endl;
		cout<<grade<<setw(10)<<sushe<<endl;
	}
	void setgr(int gr)
	{ grade=gr;}
	void setsu(int su)
	{ sushe=su;}
	int getgr(){return grade;}                                       //�༶
	int getsu(){return sushe;}                                       //����
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
	studentbase()                                                   //��ѧ����Ϣ��student.txt��ȡ��read[]��
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
     void delnu(int n)                                              //�����ɾ��
	 {
		 int i,y=0;   char x;
         for ( i=0;i<=top;i++) 
		 {   
			 if (read[i].getno()==n)
			 { 
				 cout<<"��ѧ�������"<<endl;
                 cout<<setw(10)<<read[i].getno()<<setw(10)<<read[i].getname()<<setw(10)<<read[i].getage()<<setw(10)<<read[i].getsex()<<setw(10)<<read[i].getgr()<<setw(10)<<read[i].getsu()<<endl;  
                 cout<<"�Ƿ�ȷ��ɾ������Y/N��"<<endl;
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
				cout<<"δɾ����ѧ����"<<endl;
			}
               else
			   { 
				cout<<"ɾ�������ϢΪ��"<<endl;
	            for (int i=0;i<=top;i++) 
                 read[i].show3(); 
			   }
	 }
	
       void delname(char*na)                                       //������ɾ��
	   {
		   int i,y=0;     
		   char x;
           for ( i=0;i<=top;i++) 
		   {
			   if(strcmp(read[i].getname(),na)==0)
                 cout<<setw(10)<<read[i].getno()<<setw(10)<<read[i].getname()<<setw(10)<<read[i].getage()<<setw(10)<<read[i].getsex()<<setw(10)<<read[i].getgr()<<setw(10)<<read[i].getsu()<<endl;  
                 cout<<"�Ƿ�ȷ��ɾ������Y/N��"<<endl;
                 cin>>x;   
                   if(x=='Y'||x=='y')
				   {
					   y++;  
					   for(;i<=top-1;i++) read[i]=read[i+1];
                       top--;                                      //ÿɾ��һ������һ��
				   }
			 }
            if(y==0)
			{ 
				cout<<"δɾ����ѧ����"<<endl;
			}
               else
			   { 
				 cout<<"ɾ�������ϢΪ��"<<endl;
	             for (int i=0;i<=top;i++) 
                  read[i].show3(); 
			   }
	 }
      void clear()   
	  { top=-1; }                                                 
      int add3(int n,char *na,int ag,char *se ,int gr,int su)        
	  { 
		  student *p=query(n); 
           if (p==NULL)                                             //�����ڱ����n��ѧ����ִ������
		   {  
			   top++;  
			   read[top].add3(n,na,ag,se,gr,su); 
               return 1; 
		   }   
               return 0;  
	  }
       student *query(int n)                                        //�ж��Ƿ���ڱ����n��ѧ��
	   {
		   for (int i=0;i<=top;i++) 
              if(read[i].getno()==n)    
             return &read[i]; 
              return NULL; 
	   } 
       student *query1(char *na)                                   //�жϽ�Ҫ���ӵ������Ƿ����
	   { 
		   for (int i=0;i<=top;i++) 
           if(strcmp(read[i].getname(),na)==0 )   
			return &read[i]; 
            return NULL; 
	   } 
     void disp()                                                   //ѧ����Ϣ��ʾ 
	 { 
		 for (int i=0;i<=top;i++) 
          read[i].show3(); 
	 } 
     void data();                                                  //����ѧ������ά������
     ~studentbase()                                                //��read[]�е���Ϣ���뵽student.txt�� 
	 { 
		 fstream file("student.txt",ios::out); 
         for (int i=0;i<=top;i++) 
         file.write((char*)&read[i],sizeof(read[i])); 
         file.close();
	 } 
}; 
      void studentbase::data()                                       //����ѧ��ά�� 
	  { 
		  int choice=1;    
		  int b=1;                                                   //��Ǳ���
          char x; 
		  int nan=0;                                                 //��ѧ��
          int nv=0;                                                  //Ůѧ�� 
          char name[20];                                             //����
          int number;                                                //���    
          int age;                                                   //����
		  char sex[4];                                               //�Ա�
          int gr;                                                    //�༶
		  int su;                                                    //����
          student *r;
          while (choice!=0) 
		  {
	         cout<<setw(15)<<"1������"<<endl;
			 cout<<setw(15)<<"2������"<<endl; 
			 cout<<setw(15)<<"3��ɾ��"<<endl; 
			 cout<<setw(15)<<"4������"<<endl; 
		     cout<<setw(15)<<"5����ʾ"<<endl; 
			 cout<<setw(15)<<"6��ȫɾ"<<endl;  
			 cout<<setw(15)<<"0���˳�=>";  
             cin>>choice; 
            switch (choice) 
			{ 
			   case 1:                                                //����
            
               system("cls");                                         //����
               cout<<"����ѧ����ţ�"; 
			   cin>>number; 
               cout<<"����ѧ��������";
			   cin>>name;
               cout<<"����ѧ������: "; 
			   cin>>age;
               cout<<"����ѧ���Ա�m��f����";
			   cin>>sex;
              if(strcmp("m",sex)!=0&&strcmp("f",sex)!=0)
			  {
				  while(b)
				  {
					  cout<<"�����Ա��������������룺"<<endl;  
					  cin>>sex;
                      if(strcmp("m",sex)==0||strcmp("f",sex)==0)
                       b=0; 
				  }
			  }   
               if(strcmp("m",sex)==0)
			   {nan++;}                                                 //ͳ����Ůѧ��������
                 else       
				 {nv++;}
                cout<<"����ѧ�����ڰ༶��"; 
			    cin>>gr;
                cout<<"����ѧ����������:";  
			    cin>>su; 
                add3(number,name,age,sex,gr,su);
			    break; 
                case 2:                                                  //���ݲ�ѯ�������
               
                 system("cls");
			     cout<<" ����Ÿ���1"<<endl;
			     cout<<" ����������2"<<endl;
			     cout<<" ���� 0"<<endl;
			     cin>>b;
                 while(b)
				 {
				   switch(b)
				  {
				     case 1:
                     cout<<"����ѧ����ţ�";
					 cin>>number; 
                     r=query(number); 
                     if (r==NULL) 
					{ cout<<"��ѧ��������"<<endl; break; } 
						r->show3();
                      cout<<"�Ƿ�ȷ�ϸ������ڰ༶����Y/N��"<<endl;
                       cin>>x;
                     if(x=='Y'||x=='y')
					 {
						 cout<<"�����µİ༶��"<<endl;  
					     cin>>gr;       
						 r->setgr(gr);
                        add3(number,name,age,sex,gr,su);
					 }
                      cout<<"�Ƿ�ȷ�ϸ������᣿��Y/N��"<<endl;
					  cin>>x;
                      if(x=='Y'||x=='y')
					  { 
						  cout<<"�������µ�����"<<endl; 
                           cin>>su;          
						   r->setsu(su); 
						   add3(number,name,age,sex,gr,su);
					  }
                        r->show3();   break;
                      case 2:
                       cout<<"����ѧ��������"; cin>>name; 
                       r=query1(name); 
                        if (r==NULL) 
						{cout<<"��ѧ��������"<<endl; break; } 
                         r->show3();
                         cout<<"�Ƿ�ȷ�ϸ��İ༶����Y/N��"<<endl;    cin>>x;
                          if(x=='Y'||x=='y')
						  { cout<<"�����µ����᣺"<<endl; 
                             cin>>gr; r->setgr(gr);
							 add3(number,name,age,sex,gr,su);
						  }
                         cout<<"�Ƿ�ȷ�ϸ������᣿��Y/N��"<<endl;  cin>>x;
                           if(x=='Y'||x=='y')
						   { cout<<"�������µ�����"<<endl; 
                              cin>>su; r->setsu(su);
							  add3(number,name,age,sex,gr,su);
						   }
                            r->show3();  break;
                       case 3:break;
				   }  
				   break;
				 }  
				 break;
                case 3:                                                       //ɾ��
                
                 system("cls");
                 cout<<" �����ɾ�� 1"<<endl;
			     cout<<" ������ɾ�� 2"<<endl;
			     cout<<" ���� 0"<<endl;
                 cin>>b;
                while(b!=0)
				{
					switch(b)
					{
					 case 1: 
                        cout<<"����ѧ����ţ�"; 
			            cin>>number;
                        r=query(number); 
                        if (r==NULL) 
						{cout<<"��ѧ��������"<<endl; break; } 
                         delnu(number); b=0;   break;
	                  case 2:
                      cout<<"����ѧ��������"<<endl;
					  cin>>name;
                      r=query1(name); 
                       if (r==NULL) 
					   {cout<<"��ѧ��������"<<endl; break; } 
	                   delname(name);b=0;  break;
	                  case 3:break;
					}  
					break; 
				} 
				break;
                case 4:                                                      //����
               
                system("cls");
				 cout<<" ����Ų��� 1"<<endl;
			     cout<<" ���������� 2"<<endl;
			     cout<<" ���� 0"<<endl;
                 cin>>b;
                 while(b!=0)
				 { 
					 switch(b) 
					 {
					   case 1: 
                         cout<<"����ѧ����ţ�"; cin>>number; 
                         r=query(number); 
                         if (r==NULL) 
						 { cout<<"��ѧ��������"<<endl; break; } 
                            r->show3();  break;
                       case 2:
                          cout<<"����ѧ������ :";cin>>name;
                           r=query1(name);
                           if (r==NULL) 
						   { cout<<"��ѧ��������"<<endl; break; } 
                             r->show3();  break; 
					   case 3:         break;
					 }
					 break;
				 }
				 break;
                 case 5:                                                        //��ʾ��Ϣ
               
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
		cout<<"������ְ��:"<<endl;
        cin>>zhicheng;
        cout<<"��������ְʱ��:"<<endl;
		cin>>time;
	    cout<<"������רҵ:"<<endl;
		cin>>project;
	}
	char *getzhi(){return zhicheng;}                                          //ְ��
	int  gettime(){return time;}                                              //��ְʱ��
	char *getpro(){return project;}                                           //רҵ
	void setzhi(char zhi[])                                                   //����ְ��
	{
		strcpy(zhicheng,zhi);
	}
     void settime(int t)                                                      //������ְʱ��
	 {
	      time=t;
	 }
     void setpro(char pro[])                                                  //����רҵ
	 {
	      strcpy(project,pro);
	 }
	void show2()
	{
		show();
		cout<<"ְ��"<<setw(10)<<"��ְʱ��"<<setw(10)<<"רҵ"<<endl;
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
	teacherbase()                                                   //��ְ����Ϣ��teacher.txt��ȡ��read[]��
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
     void delnu(int n)                                                       //�����ɾ��
	 {
		 int i,y=0;   char x;
         for ( i=0;i<=top;i++) 
		 {   
			 if (read[i].getno()==n)
			 { 
				 cout<<"�ý�ʦ�����"<<endl;
                 read[i].show2();
			 }
                 cout<<"�Ƿ�ȷ��ɾ������Y/N��"<<endl;
                 cin>>x;   
                   if(x=='Y'||x=='y')
				   {
					   y++;  
					   for(;i<=top-1;i++) read[i]=read[i+1];
                       top--;                                           //ÿɾ��һ���������Ǽ���һ��
				   }
			 
		 }
            if(y==0)
			{ 
				cout<<"δɾ���ý�ʦ��"<<endl;
			}
               else
			   { 
				cout<<"ɾ�������ϢΪ��"<<endl;
	            for (int i=0;i<=top;i++) 
                 read[i].show2(); 
			   }
	 }
	
       void delname(char*na)                                                   //������ɾ��
	   {
		   int i,y=0;     
		   char x;
           for ( i=0;i<=top;i++) 
		   {
			   if(strcmp(read[i].getname(),na)==0)
				 cout<<setw(10)<<"���"<<setw(10)<<"����"<<setw(10)<<"����"<<setw(10)<<"�Ա�"<<setw(10)<<"ϵ��"<<setw(10)<<"ְ��"<<endl; 
                 cout<<setw(10)<<read[i].getno()<<setw(10)<<read[i].getname()<<setw(10)<<read[i].getage()<<setw(10)<<read[i].getsex()<<setw(10)
					 <<read[i].gettime()<<setw(10)<<read[i].getzhi()<<setw(10)<<read[i].getpro()<<endl;  
                 cout<<"�Ƿ�ȷ��ɾ������Y/N��"<<endl;
                 cin>>x;   
                   if(x=='Y'||x=='y')
				   {
					   y++;  
					   for(;i<=top-1;i++) read[i]=read[i+1];
                       top--;                                               //ÿɾ��һ���������Ǽ���һ��
				   }
			 }
            if(y==0)
			{ 
				cout<<"δɾ���ý�ʦ��"<<endl;
			}
               else
			   { 
				 cout<<"ɾ�������ϢΪ��"<<endl;
	             for (int i=0;i<=top;i++) 
                  read[i].show2(); 
			   }
	 }
      void clear()   
	  { top=-1; }                                                                   
      int add2 (int n,char *na,int ag,char *se ,char *zhi,int ti,char *pro)         //���ӽ�ʦ
	  {
		  teacher *p=query(n); 
           if (p==NULL)                                                  //�����ڱ����n�Ľ�ʦ��ִ������
		   {  
			   top++;  
			   read[top].add2(n,na,ag,se,zhi,ti,pro); 
               return 1; 
		   }   
               return 0;  
	  }
       teacher *query(int n)                                             //�ж��Ƿ���ڱ����n�Ľ�ʦ
	   {
		   for (int i=0;i<=top;i++) 
              if(read[i].getno()==n)    
             return &read[i]; 
              return NULL; 
	   } 
       teacher *query1(char *na)                                          //�жϽ�Ҫ���ӵ������Ƿ����
	   { 
		   for (int i=0;i<=top;i++) 
           if(strcmp(read[i].getname(),na)==0 )   
			return &read[i]; 
            return NULL; 
	   } 
     void disp()                                                              //��ʦ��Ϣ��ʾ 
	 { 
		 for (int i=0;i<=top;i++) 
          read[i].show2(); 
	 } 
     void data();                                                           //������ʦ����ά������
     ~teacherbase()                                                         //��read[]�е���Ϣ���뵽teacher.txt�� 
	 { 
		 fstream file("teacher.txt",ios::out); 
         for (int i=0;i<=top;i++) 
         file.write((char*)&read[i],sizeof(read[i])); 
         file.close();
	 } 
}; 
      void teacherbase::data()                                                  //�����ʦά�� 
	  { 
		  int choice=1;   
		  int b=1;                                                              //��Ǳ���
          char x; 
		  int nan=0;                                                            //�н�ʦ
          int nv=0;                                                             //Ů��ʦ 
          char name[20];                                                        //����
          int number;                                                           //���    
          int age;                                                              //����
          char zhi[20];                                                         //ְ��   
          char sex[4];                                                          //�Ա�
          char pro[20];                                                         //רҵ
		  int ti;                                                               //ʱ��
          teacher *r;
          while (choice!=0) 
		  {
	         cout<<setw(15)<<"1������"<<endl;
			 cout<<setw(15)<<"2������"<<endl; 
			 cout<<setw(15)<<"3��ɾ��"<<endl; 
			 cout<<setw(15)<<"4������"<<endl; 
		     cout<<setw(15)<<"5����ʾ"<<endl; 
			 cout<<setw(15)<<"6��ȫɾ"<<endl;  
			 cout<<setw(15)<<"0���˳�=>";  
             cin>>choice; 
            switch (choice) 
			{ 
			   case 1:                                                           //����
              
               system("cls");                                                    //����
               cout<<"�����ʦ��ţ�"; 
			   cin>>number; 
               cout<<"�����ʦ������";
			   cin>>name;
               cout<<"�����ʦ����: "; 
			   cin>>age;
               cout<<"�����ʦ�Ա�m��f����";
			   cin>>sex;
              if(strcmp("m",sex)!=0&&strcmp("f",sex)!=0)
			  {
				  while(b)
				  {
					  cout<<"�����Ա��������������룺"<<endl;  
					  cin>>sex;
                      if(strcmp("m",sex)==0||strcmp("f",sex)==0)
                       b=0; 
				  }
			  }   
               if(strcmp("m",sex)==0)
			   {nan++;}                                                      //ͳ����Ů��ʦ������
                 else       
				 {nv++;}
                cout<<"�����ʦ����רҵ��"; 
			    cin>>pro;
                cout<<"�����ʦ��ְ��:";  
			    cin>>zhi; 
				cout<<"�����ʦ����ְʱ�䣺";
				cin>>ti;
                add2(number,name,age,sex,zhi,ti,pro);
			    break; 
                case 2:                                                        //���ݲ�ѯ�������
                
                 system("cls");
			     cout<<" ����Ÿ���1"<<endl;
			     cout<<" ����������2"<<endl;
			     cout<<" ���� 0"<<endl;
			     cin>>b;
                 while(b)
				 {
				   switch(b)
				  {
				     case 1:
                     cout<<"�����ʦ��ţ�";
					 cin>>number; 
                     r=query(number); 
                     if (r==NULL) 
					{ cout<<"�ý�ʦ������"<<endl; break; } 
						r->show2();
                      cout<<"�Ƿ�ȷ�ϸ���ְ�ƣ���Y/N��"<<endl;
                       cin>>x;
                     if(x=='Y'||x=='y')
					 {
						 cout<<"�����µ�ְ�ƣ�"<<endl;  
					     cin>>zhi;       
						 r->setzhi(zhi);
                        add2(number,name,age,sex,zhi,ti,pro);
					 }
                      cout<<"�Ƿ�ȷ�ϸ�����ְʱ�䣿��Y/N��"<<endl;
					  cin>>x;
                      if(x=='Y'||x=='y')
					  { 
						  cout<<"�������µ���ְʱ��"<<endl; 
                           cin>>ti;          
						   r->settime(ti); 
						   add2(number,name,age,sex,zhi,ti,pro);
					  }
					  cout<<"�Ƿ�ȷ�ϸ���רҵ����Y/N��"<<endl;
					  cin>>x;
                      if(x=='Y'||x=='y')
					  { 
						  cout<<"�������µ�רҵ"<<endl; 
                           cin>>pro;          
						   r->setpro(pro); 
						   add2(number,name,age,sex,zhi,ti,pro);
					  }
                        r->show2();   break;

                      case 2:
                       cout<<"�����ʦ������"; cin>>name; 
                       r=query1(name); 
                        if (r==NULL) 
						{cout<<"�ý�ʦ������"<<endl; break; } 
                         r->show2();
						 cout<<"�Ƿ�ȷ�ϸ���ְ�ƣ���Y/N��"<<endl;
                         cin>>x;
                         if(x=='Y'||x=='y')
						 {
						   cout<<"�����µ�ְ�ƣ�"<<endl;  
					       cin>>zhi;       
						   r->setzhi(zhi);
                           add2(number,name,age,sex,zhi,ti,pro);
						 }
                         cout<<"�Ƿ�ȷ�ϸ�����ְʱ�䣿��Y/N��"<<endl;
					     cin>>x;
                        if(x=='Y'||x=='y')
						{ 
						   cout<<"�������µ���ְʱ��"<<endl; 
                           cin>>ti;          
						   r->settime(ti); 
						   add2(number,name,age,sex,zhi,ti,pro);
						}
					    cout<<"�Ƿ�ȷ�ϸ���רҵ����Y/N��"<<endl;
					    cin>>x;
                        if(x=='Y'||x=='y')
						{ 
						   cout<<"�������µ�רҵ"<<endl; 
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
                case 3:                                                        //ɾ��
               
                 system("cls");
                 cout<<" �����ɾ�� 1"<<endl;
			     cout<<" ������ɾ�� 2"<<endl;
			     cout<<" ���� 0"<<endl;
                 cin>>b;
                while(b!=0)
				{
					switch(b)
					{
					 case 1: 
                        cout<<"�����ʦ��ţ�"; 
			            cin>>number;
                        r=query(number); 
                        if (r==NULL) 
						{cout<<"�ý�ʦ������"<<endl; break; } 
                         delnu(number); b=0;   break;
	                  case 2:
                      cout<<"�����ʦ������"<<endl;
					  cin>>name;
                      r=query1(name); 
                       if (r==NULL) 
					   {cout<<"�ý�ʦ������"<<endl; break; } 
	                   delname(name);b=0;  break;
	                  case 3:break;
					}  
					break; 
				} 
				break;
                case 4:                                                      //����
              
                system("cls");
				 cout<<" ����Ų��� 1"<<endl;
			     cout<<" ���������� 2"<<endl;
			     cout<<" ���� 0"<<endl;
                 cin>>b;
                 while(b!=0)
				 { 
					 switch(b) 
					 {
					   case 1: 
                         cout<<"�����ʦ��ţ�"; cin>>number; 
                         r=query(number); 
                         if (r==NULL) 
						 { cout<<"�ý�ʦ������"<<endl; break; } 
                            r->show2();  break;
                       case 2:
                          cout<<"�����ʦ������ :";cin>>name;
                           r=query1(name);
                           if (r==NULL) 
						   { cout<<"�ý�ʦ������"<<endl; break; } 
                             r->show2();  break; 
					   case 3:         break;
					 }
					 break;
				 }
				 break;
                 case 5:                                                            //��ʾ��Ϣ
                 
                 system("cls");
                  disp();   break; 
                 case 6:                                                            
               
                  system("cls");   clear();     break;
          
             }
          }
}

class  leader: public people                                                        //ְ����
{
private:
	char bumen[20];
	char zhineng[20];
public:
	void set1()
	{
		set();
		cout<<"��������ְ����:"<<endl;
		cin>>bumen;
     	cout<<"������ְ��:"<<endl;
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
		cout<<"����"<<setw(10)<<"ְ��"<<endl;
		cout<<bumen<<setw(10)<<zhineng<<endl;
	}
	void add1(int n,char *na,int ag,char *se,char *bu,char *zhi)
	{
		add( n, na, ag, se);
		strcpy(bumen,bu);
		strcpy(zhineng,zhi);
	}
	char *getbu(){return bumen;}                                 //����
	char *getzhi(){return zhineng;}                              //ְ��
};
class staff
{
private:
	int top;
	leader read[Maxr];
public:
	staff()                                                   //��ְ����Ϣ��staff.txt��ȡ��read[]��
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
     void delnu(int n)                                                  //�����ɾ��
	 {
		 int i,y=0;   char x;
         for ( i=0;i<=top;i++) 
		 {   
			 if (read[i].getno()==n)
			 { 
				 cout<<"��ְ�������"<<endl;
                 cout<<setw(10)<<"���"<<setw(10)<<"����"<<setw(10)<<"����"<<setw(10)<<"�Ա�"<<setw(10)<<"����"<<setw(10)<<"ְ��"<<endl; 
cout<<setw(10)<<read[i].getno()<<setw(10)<<read[i].getname()<<setw(10)<<read[i].getage()<<setw(10)<<read[i].getsex()<<setw(10)<<read[i].getbu()<<setw(10)<<read[i].getzhi()<<endl;  
                 cout<<"�Ƿ�ȷ��ɾ������Y/N��"<<endl;
                 cin>>x;   
                   if(x=='Y'||x=='y')
				   {
					   y++;  
					   for(;i<=top-1;i++) read[i]=read[i+1];
                       top--;                                       //ÿɾ��һ�������Ǽ���һ��
				   }
			 }
		 }
            if(y==0)
			{ 
				cout<<"δɾ����ְ��"<<endl;
			}
               else
			   { 
				cout<<"ɾ�������ϢΪ��"<<endl;
	            for (int i=0;i<=top;i++) 
                 read[i].show1(); 
			   }
	 }
	      void delname(char*na)                                        //������ɾ��
	   {
		   int i,y=0;     
		   char x;
           for ( i=0;i<=top;i++) 
		   {
			   if(strcmp(read[i].getname(),na)==0)
				 cout<<setw(10)<<"���"<<setw(10)<<"����"<<setw(10)<<"����"<<setw(10)<<"�Ա�"<<setw(10)<<"����"<<setw(10)<<"ְ��"<<endl; 
                 cout<<setw(10)<<read[i].getno()<<setw(10)<<read[i].getname()<<setw(10)<<read[i].getage()<<setw(10)<<read[i].getsex()<<setw(10)<<read[i].getbu()<<setw(10)<<read[i].getzhi()<<endl;  
                 cout<<"�Ƿ�ȷ��ɾ������Y/N��"<<endl;
                 cin>>x;   
                   if(x=='Y'||x=='y')
				   {
					   y++;  
					   for(;i<=top-1;i++) read[i]=read[i+1];
                       top--;                                          //ÿɾ��һ�������Ǽ���һ��
				   }
			 }
            if(y==0)
			{ 
				cout<<"δɾ����ְ����"<<endl;
			}
               else
			   { 
				 cout<<"ɾ�������ϢΪ��"<<endl;
	             for (int i=0;i<=top;i++) 
                  read[i].show1(); 
			   }
	 }
      void clear()   
	  { top=-1; }                                                          
      int add (int n,char *na,int ag,char *se ,char *bu,char *zhi)         //����ְ�� 
	  { 
		  leader *p=query(n); 
           if (p==NULL)                                                    //�����ڱ����n��ְ����ִ������
		   {  
			   top++;  
			   read[top].add1(n,na,ag,se,bu,zhi); 
               return 1; 
		   }   
               return 0;  
	  }
       leader *query(int n)                                                 //�ж��Ƿ���ڱ����n��ְ��
	   {
		   for (int i=0;i<=top;i++) 
              if(read[i].getno()==n)    
             return &read[i]; 
              return NULL; 
	   } 
       leader *query1(char *na)                                             //�жϽ�Ҫ���ӵ������Ƿ����
	   { 
		   for (int i=0;i<=top;i++) 
           if(strcmp(read[i].getname(),na)==0 )   
			return &read[i]; 
            return NULL; 
	   } 
     void disp()                                                            //ְ����Ϣ��ʾ 
	 { 
		 for (int i=0;i<=top;i++) 
          read[i].show1(); 
	 } 
     void data();                                                           //����ְ������ά������
     ~staff()                                                               //��read[]�е���Ϣ���絽staff.txt�� 
	 { 
		 fstream file("staff.txt",ios::out); 
         for (int i=0;i<=top;i++) 
         file.write((char*)&read[i],sizeof(read[i])); 
         file.close();
	 } 
}; 
      void staff::data()                                                   //����ְ��ά�� 
	  { 
		  int choice=1;    
		  int b=1;                                                         //��Ǳ���
          char x; 
		  int nan=0;                                                       //��ְ��
          int nv=0;                                                        //Ůְ��  
          char name[20];                                                   //����
          int number;                                                      //���    
          int age;                                                         //����
          char zhi[20];                                                    //ְ��   
          char sex[4];                                                     //�Ա�
          char bu[20];                                                     //����  
          leader *r;
          while (choice!=0) 
		  {
	         cout<<setw(15)<<"1������"<<endl;
			 cout<<setw(15)<<"2������"<<endl; 
			 cout<<setw(15)<<"3��ɾ��"<<endl; 
			 cout<<setw(15)<<"4������"<<endl; 
		     cout<<setw(15)<<"5����ʾ"<<endl; 
			 cout<<setw(15)<<"6��ȫɾ"<<endl;  
			 cout<<setw(15)<<"0���˳�=>";  
             cin>>choice; 
            switch (choice) 
			{ 
			   case 1:                                                      //����
               
               system("cls");                                               //����
               cout<<"����ְ����ţ�"; 
			   cin>>number; 
               cout<<"����ְ��������";
			   cin>>name;
               cout<<"����ְ������: "; 
			   cin>>age;
               cout<<"����ְ���Ա�m or f����";cin>>sex;
              if(strcmp("m",sex)!=0&&strcmp("f",sex)!=0)
			  {
				  while(b)
				  {
					  cout<<"�����Ա��������������룺"<<endl;  
					  cin>>sex;
                      if(strcmp("m",sex)==0||strcmp("f",sex)==0)
                       b=0; 
				  }
			  }   
               if(strcmp("m",sex)==0)
			   {nan++;}                                                     //ͳ����Ůְ��������
                 else       
				 {nv++;}
                cout<<"����ְ�����ڲ��ţ�"; 
			    cin>>bu;
                cout<<"����ְ����ְ��:";  
			    cin>>zhi; 
                add(number,name,age,sex,bu,zhi);
			    break; 
                case 2:                                                     //���ݲ�ѯ�������
                 
                 system("cls");
			     cout<<" ����Ÿ���1"<<endl;
			     cout<<" ����������2"<<endl;
			     cout<<" ���� 0"<<endl;
			     cin>>b;
                 while(b)
				 {
				   switch(b)
				  {
				     case 1:
                     cout<<"����ְ����ţ�";
					 cin>>number; 
                     r=query(number); 
                     if (r==NULL) 
					{ cout<<"��ְ��������"<<endl; break; } 
						r->show1();
                      cout<<"�Ƿ�ȷ�ϸ�����ְ���ţ���Y/N��"<<endl;
                       cin>>x;
                     if(x=='Y'||x=='y')
					 {
						 cout<<"�����µ���ְ���ţ�"<<endl;  
					     cin>>bu;       
						 r->setbu(bu);
                        add(number,name,age,sex,bu,zhi);
					 }
                      cout<<"�Ƿ�ȷ�ϸ���ְ�ܣ���Y/N��"<<endl;
					  cin>>x;
                      if(x=='Y'||x=='y')
					  { 
						  cout<<"�������µ�ְ��"<<endl; 
                           cin>>zhi;          
						   r->setzhi(zhi); 
						   add(number,name,age,sex,bu,zhi);
					  }
                        r->show1();   break;
                      case 2:
                       cout<<"����ְ��������"; cin>>name; 
                       r=query1(name); 
                        if (r==NULL) 
						{cout<<"��ְ��������"<<endl; break; } 
                         r->show1();
                         cout<<"�Ƿ�ȷ�ϸ�����ְ���ţ���Y/N��"<<endl;    cin>>x;
                          if(x=='Y'||x=='y')
						  { cout<<"�����µ���ְ���ţ�"<<endl; 
                             cin>>bu; r->setbu(bu);
							 add(number,name,age,sex,bu,zhi);
						  }
                         cout<<"�Ƿ�ȷ�ϸ���ְ�ܣ���Y/N��"<<endl;  cin>>x;
                           if(x=='Y'||x=='y')
						   { cout<<"�������µ�ְ��"<<endl; 
                              cin>>zhi; r->setzhi(zhi);
							  add(number,name,age,sex,bu,zhi);
						   }
                            r->show1();  break;
                       case 3:break;
				   }  
				   break;
				 }  
				 break;
                case 3:                                                       //ɾ����Ϣ
               
                 system("cls");
                 cout<<" �����ɾ�� 1"<<endl;
			     cout<<" ������ɾ�� 2"<<endl;
			     cout<<" ���� 0"<<endl;
                 cin>>b;
                while(b!=0)
				{
					switch(b)
					{
					 case 1: 
                        cout<<"����ְ����ţ�"; 
			            cin>>number;
                        r=query(number); 
                        if (r==NULL) 
						{cout<<"��ְ��������"<<endl; break; } 
                         delnu(number); b=0;   break;
	                  case 2:
                      cout<<"����ְ��������"<<endl;
					  cin>>name;
                      r=query1(name); 
                       if (r==NULL) 
					   {cout<<"��ְ��������"<<endl; break; } 
	                   delname(name);b=0;  break;
	                  case 3:break;
					}  
					break; 
				} 
				break;
                case 4:                                                      //������Ϣ
               
                system("cls");
				 cout<<" ����Ų��� 1"<<endl;
			     cout<<" ���������� 2"<<endl;
			     cout<<" ���� 0"<<endl;
                 cin>>b;
                 while(b!=0)
				 { 
					 switch(b) 
					 {
					   case 1: 
                         cout<<"����ְ����ţ�"; cin>>number; 
                         r=query(number); 
                         if (r==NULL) 
						 { cout<<"��ְ��������"<<endl; break; } 
                            r->show1();  break;
                       case 2:
                          cout<<"����ְ������ :";cin>>name;
                           r=query1(name);
                           if (r==NULL) 
						   { cout<<"��ְ��������"<<endl; break; } 
                             r->show1();  break; 
					   case 3:         break;
					 }
					 break;
				 }
				 break;
                 case 5:                                                       //��ʾ��Ϣ
                  
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
  cout<<setw(20)<<"         ��ӭʹ�����Ͻ�����Ա����ϵͳ"<<endl; 
  cout<<endl;   cout<<"�����ˣ���Ц�� 20102889 ��� 20102872 ���� 20100147 "<<endl; 
  cout<<setw(20)<<""<<endl; 
  cout<<setw(20)<<"              ��ѡ��������Ĳ���\n"; 
  cout<<setw(20)<<"                                                                                "<<endl;
  cout<<setw(20)<<"                1.ѧ����Ϣ����\n"; 
  cout<<setw(20)<<"                                                                                "<<endl;
  cout<<setw(20)<<"                2.��ʦ��Ϣ����\n";
  cout<<setw(20)<<"                                                                                "<<endl;
  cout<<setw(20)<<"                3.ְ����Ϣ����\n";
  cout<<setw(20)<<"                                                                                "<<endl;
  cout<<setw(20)<<"                0.�˳���Ϣ����\n"; 
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
 

