import os
import platform
import mysql.connector
import pandas as pd

mydb=mysql.connector.connect(host=&quot;localhost&quot;,\
user=&quot;root&quot;,\

password=&quot;root&quot;,\
database=&quot;Bank&quot;)
mycursor=mydb.cursor()

def AccInsert():
L=[]
Accno=int(input(&quot;Enter the Account number : &quot;))
L.append(Accno)
name=input(&quot;Enter the Customer Name: &quot;)
L.append(name)
age=int(input(&quot;Enter Age of Customer : &quot;))
L.append(age)
occup=input(&quot;Enter the Customer Occupation : &quot;)
L.append(occup)
Address=input(&quot;Enter the Address of the Customer : &quot;)
L.append(Address)
Mob=int(input(&quot;Enter the Mobile number : &quot;))
L.append(Mob)
Aadharno=int(input(&quot;Enter the Aadhar number : &quot;))
L.append(Aadharno)
Amt=float(input(&quot;Enter the Money Deposited : &quot;))
L.append(Amt)
AccType=input(&quot;Enter the Account Type (Saving/RD/PPF/Current) : &quot;)
L.append(AccType)
cust=(L)
sql=&#39;&#39;&#39;Insert into ACCOUNT(Accno
,Name,Age,occu,Address,Mob,Aadharno,amt,AccType)
values(%s,%s,%s, %s,%s,%s, %s,%s,%s)&#39;&#39;&#39;
mycursor.execute(sql,cust)
mydb.commit()

def AccView():
print(&quot;Select the search criteria : &quot;)
print(&quot;1. Acc no&quot;)
print(&quot;2. Name&quot;)
print(&quot;3. Mobile&quot;)
print(&quot;4. Adhar&quot;)
print(&quot;5. View All&quot;)
ch=int(input(&quot;Enter the choice : &quot;))
if ch==1:
s=int(input(&quot;Enter ACC no : &quot;))
rl=(s,)
sql=&quot;select * from account where Accno=%s&quot;
mycursor.execute(sql,rl)
elif ch==2:
s=input(&quot;Enter Name : &quot;)
rl=(s,)
sql=&quot;select * from account where Name=%s&quot;
mycursor.execute(sql,rl)
elif ch==3:
s=int(input(&quot;Enter Mobile No : &quot;))
rl=(s,)
sql=&quot;select * from account where Mob=%s&quot;
mycursor.execute(sql,rl)
elif ch==4:
s=input(&quot;Enter Adhar : &quot;)
rl=(s,)
sql=&quot;select * from account where Aadharno=%s&quot;
mycursor.execute(sql,rl)
elif ch==5:
sql=&quot;select * from account&quot;

mycursor.execute(sql)
res=mycursor.fetchall()
print(&quot;The Customer details are as follows : &quot;)
k=pd.DataFrame(res,columns=[&#39;AcNo&#39;,&#39;Name&#39;,&#39;Age&#39;,&#39;Occn&#39;,&#39;Add&#39;,&#39;Mob&#39;,&#39;Aadh&#39;,&#39;Amt&#39;,&#39;A
ccTy&#39;])
print(k)

def AccDeposit():
L=[]
Accno=int(input(&quot;Enter the Account number : &quot;))
L.append(Accno)
Amtdeposit=eval(input(&quot;Enter the Amount to be deposited : &quot;))
L.append(Amtdeposit)
month=input(&quot;Enter month of Salary : &quot;)
L.append(month)
cust=(L)
sql=&quot;Insert into amt(Accno,Amtdeposit,Month) values(%s,%s,%s)&quot;
mycursor.execute(sql,cust)
mydb.commit()
def accView():
print(&quot;Please enter the details to view the Money details :&quot;)
Accno=int(input(&quot;Enter the Account number of the Customer whose amount is to
be viewed : &quot;))
sql=&#39;&#39;&#39;Select Account.Accno, Account.Name,
Account.Age,Account.occu,Account.Address,Account.Mob,Account.Aadharno,Accou
nt.Amt,Account.Ac
cType, sum(amt.Amtdeposit), amt.month from Account INNER JOIN amt ON
Account.Accno=amt.Accno and amt.Accno = %s&#39;&#39;&#39;
rl=(Accno,)
mycursor.execute(sql,rl)
res=mycursor.fetchall()

for x in res:
print(x)
def closeAcc():
Accno=int(input(&quot;Enter the Account number of the Customer to be closed : &quot;))
rl=(Accno,)
sql=&quot;Delete from amt where Accno=%s&quot;
mycursor.execute(sql,rl)
sql=&quot;Delete from Account where Accno=%s&quot;
mydb.commit()
def MenuSet():
print(&quot;Enter 1 : To Add Customer&quot;)
print(&quot;Enter 2 : To View Customer &quot;)
print(&quot;Enter 3 : To Deposit Money &quot;)
print(&quot;Enter 4 : To Close Account&quot;)
print(&quot;Enter 5 : To View All Customer Details&quot;)
try:
userInput = int(input(&quot;Please Select An Above Option: &quot;))
except ValueError:
exit(&quot;\nHy! That&#39;s Not A Number&quot;)
else:
print(&quot;\n&quot;)
if(userInput == 1):
AccInsert()
elif (userInput==2):
AccView()
elif (userInput==3):
AccDeposit()
elif (userInput==4):
closeAcc()
elif (userInput==5):

accView()
else:
print(&quot;Enter correct choice. . . &quot;)
MenuSet()
def runAgain():
runAgn = input(&quot;\nwant To Run Again Y/n: &quot;)
while(runAgn.lower() == &#39;y&#39;):
if(platform.system() == &quot;Windows&quot;):
print(os.system(&#39;cls&#39;))
else:
print(os.system(&#39;clear&#39;))
MenuSet()
runAgn = input(&quot;\nwant To Run Again Y/n: &quot;)
runAgain()
