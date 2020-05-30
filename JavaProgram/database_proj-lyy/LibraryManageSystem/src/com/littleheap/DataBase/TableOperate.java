package com.littleheap.DataBase;

import java.sql.*;
import java.util.ArrayList;
import java.util.Collection;

import com.littleheap.Book;
import com.littleheap.user;
import com.littleheap.Library;
import com.littleheap.Static.Information;

public class TableOperate {
	//驱动连接mysql
	static Statement stmt;
	static Connection conn;
	public static  void connect_mysql() {//调用Class.forName()方法加载驱动程序
    try{
    	Class.forName("com.mysql.jdbc.Driver");
    
    System.out.println("成功加载MySQL驱动-isExist_Customer");
        
    String url=Information.JDBC_URL.concat("?useSSL=false");    //JDBC的URL    
    

    conn = DriverManager.getConnection("jdbc:mysql://localhost/book?user=root&password=lyy525520&useSSL=false");
    stmt = conn.createStatement(); //创建Statement对象
    System.out.println("成功连接到数据库-isExist_Customer");
    }catch(Exception e)
    {
    	e.printStackTrace();
    }
    }
	//数据库查询连接模板
	public TableOperate() {
		try{
          
			connect_mysql();
            String sql = "select * from temp";    //要执行的SQL
            ResultSet rs = stmt.executeQuery(sql);//创建数据对象
                System.out.println("编号"+"\t"+"姓名"+"\t"+"年龄");
                while (rs.next()){
                    System.out.print(rs.getInt(1) + "\t");
                    System.out.print(rs.getString(2) + "\t");
                    System.out.print(rs.getString(3) + "\t");
                    System.out.println();
                }
                rs.close();
                stmt.close();
                conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
	}
    
	//是否存在该用户
    public static boolean isExist_Customer(String user,String password) {
    	try{
            
    		connect_mysql();
            String sql = "select * from Customer";    //要执行的SQL
            ResultSet rs = stmt.executeQuery(sql);//创建数据对象
                System.out.println("用户名"+"\t"+"\t"+"\t"+"密码");
                while (rs.next()){
                    System.out.print(rs.getString(1) + "\t");
                    System.out.print(rs.getString(2) + "\t");
                    System.out.println();
                    if(rs.getString(1).equals(user) && rs.getString(2).equals(password)) {
                        rs.close();
                        stmt.close();
                        conn.close();
                    	return true;
                    }
                }
                rs.close();
                stmt.close();
                conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
		return false;
    }
    
    //是否存在该管理员
    public static boolean isExist_Manager(String user,String password) {
    	try{
            
    		connect_mysql();
            String sql = "select * from Manager";    //要执行的SQL
            ResultSet rs = stmt.executeQuery(sql);//创建数据对象
                System.out.println("用户名"+"\t"+"\t"+"\t"+"密码");
                while (rs.next()){
                    System.out.print(rs.getString(1) + "\t");
                    System.out.print(rs.getString(2) + "\t");
                    System.out.println();
                    if(rs.getString(1).equals(user) && rs.getString(2).equals(password)) {
                        rs.close();
                        stmt.close();
                        conn.close();
                    	return true;
                    }
                }
                rs.close();
                stmt.close();
                conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
		return false;
    }

 
    //注册新用户 （第一次
    public static void regist_Customer(String user,String password) {
    	try{
    		connect_mysql();

            String sql = "insert into Customer values('"+user+"','"+password+"');";    //要执行的SQL
            
            PreparedStatement stmts = conn.prepareStatement(sql);
            stmts.executeUpdate();  
            
            stmts.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }
    
    //注册新管理员
    public static void regist_Manager(String user,String password) {
    	try{
    		connect_mysql();

            String sql = "insert into Manager values('"+user+"','"+password+"');";    //要执行的SQL
            
            PreparedStatement stmts = conn.prepareStatement(sql);
            stmts.executeUpdate();  
            
            stmts.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }
    
    //改变用户的密码
    public static void changePassword_Customer(String user,String password,String newPassword) {
    	try{
    		connect_mysql();

            String sql = "update Customer set customer_password = '"+newPassword+"' where customer_user = '"+user+"';";    //要执行的SQL
            
            PreparedStatement stmts = conn.prepareStatement(sql);
            stmts.executeUpdate();  
            
            stmts.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }
    
    //改变管理员的密码
    public static void changePassword_Manager(String user,String password,String newPassword) {
    	try{
    		connect_mysql();

            String sql = "update Manager set manager_password = '"+newPassword+"' where manager_user = '"+user+"';";    //要执行的SQL
            
            PreparedStatement stmts = conn.prepareStatement(sql);
            stmts.executeUpdate();  
            
            stmts.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }

    //是否存在该用户名
    public static boolean isExist_Customer_user(String user,String password) {
    	try{
    		connect_mysql();

            String sql = "select * from Customer";    //要执行的SQL
            ResultSet rs = stmt.executeQuery(sql);//创建数据对象
                System.out.println("用户名"+"\t"+"\t"+"\t"+"密码");
                while (rs.next()){
                    System.out.print(rs.getString(1) + "\t");
                    System.out.print(rs.getString(2) + "\t");
                    System.out.println();
                    if(rs.getString(1).equals(user)) {
                        rs.close();
                        stmt.close();
                        conn.close();
                    	return true;
                    }
                }
                rs.close();
                stmt.close();
                conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
		return false;
    }

    //是否存在该管理员名称
    public static boolean isExist_Manager_user(String user,String password) {
    	try{
    		connect_mysql();
            
            String sql = "select * from Manager";    //要执行的SQL
            ResultSet rs = stmt.executeQuery(sql);//创建数据对象
                System.out.println("用户名"+"\t"+"\t"+"\t"+"密码");
                while (rs.next()){
                    System.out.print(rs.getString(1) + "\t");
                    System.out.print(rs.getString(2) + "\t");
                    System.out.println();
                    if(rs.getString(1).equals(user)) {
                        rs.close();
                        stmt.close();
                        conn.close();
                    	return true;
                    }
                }
                rs.close();
                stmt.close();
                conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
		return false;
    }
    
    //插入新书
    public static void insertBook(String number,String classnumber,String name,String classname,String price,String state,String total) {
    	try{
    		connect_mysql();

            String sql = "insert into "+classname+"Book"+" values('"+number+"','"+classnumber+"','"+name+"','"+classname+"','"+price+"','"+state+"','"+total+"','null','null','null');";    //要执行的SQL
            
            PreparedStatement stmts = conn.prepareStatement(sql);
            stmts.executeUpdate();  
            
            stmts.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }

    //新建类别
    public static void newClass(String classnumber, String classname) {
    	try{
    		connect_mysql();

            String sql = "CREATE TABLE "+classname+"Book(number VARCHAR(255) primary key,classnumber VARCHAR(255),name VARCHAR(255),classname VARCHAR(255),price VARCHAR(255),state VARCHAR(255),total VARCHAR(255),current VARCHAR(255),dateon VARCHAR(255),dateoff VARCHAR(255));";    //要执行的SQL
            
            PreparedStatement stmts = conn.prepareStatement(sql);
            stmts.executeUpdate();  
            
            stmts.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }
    
    //删除书籍信息
    public static void deleteBook(String number, String classname) {
    	try{
    		connect_mysql();
            String sql = "delete from "+classname+"Book where number = '"+number+"';";  //要执行的SQL
            
            PreparedStatement stmts = conn.prepareStatement(sql);
            stmts.executeUpdate();  
            
            stmts.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }

    //查询某类图书信息
    public static void search_classname(String classname) {
    	Information.bookarray.clear();
    	try{
    		
    		connect_mysql();

            String sql = "select * from "+classname+"Book;";    //要执行的SQL
            ResultSet rs = stmt.executeQuery(sql);//创建数据对象
                while (rs.next()){
                	Book book = new Book();
                    book.number = rs.getString(1);
                    book.classnumber = rs.getString(2);
                    book.name = rs.getString(3);
                    book.classname = rs.getString(4);
                    book.price = rs.getString(5);
                    book.state = rs.getString(6);
                    book.total = rs.getString(7);
                    book.current = rs.getString(8);
                    book.dateon = rs.getString(9);
                    book.dateoff = rs.getString(10);
                    Information.bookarray.add(book);
                }
                rs.close();
                stmt.close();
                conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }
    
    //借书更改信息
    public static void borrowBook_Update(String classname,String number,String user,String dateoff) {
    	try{
    		connect_mysql();

            String sql = "update "+classname+"Book set state = 'out' where number = '"+number+"';\n";    //要执行的SQL
            PreparedStatement stmts_state = conn.prepareStatement(sql);
            stmts_state.executeUpdate();  
            stmts_state.close();
            
            sql = "update "+classname+"Book set current = '"+user+"' where number = '"+number+"';\n";
            PreparedStatement stmts_current = conn.prepareStatement(sql);
            stmts_current.executeUpdate();  
            stmts_current.close();
            
            sql = "update "+classname+"Book set dateoff = '"+dateoff+"' where number = '"+number+"';\n";
            PreparedStatement stmts_dateoff = conn.prepareStatement(sql);
            stmts_dateoff.executeUpdate();
            stmts_dateoff.close();
            
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }
    
  //创建用户数据库
    public static void newCustomer(String user) {
    	try{
    		connect_mysql();

            String sql = "CREATE TABLE "+user+"Customer (number VARCHAR(255) primary key,classname VARCHAR(255),name VARCHAR(255),dateoff VARCHAR(255));";    //要执行的SQL
            
            PreparedStatement stmts = conn.prepareStatement(sql);
            stmts.executeUpdate();  
            
            stmts.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }
    
    //借书注射到用户信息
    public static void borrowBook_Insert(String classname,String number,String user,String dateoff) {
    	try{
    		connect_mysql();

            String sql = "insert into "+user+"Customer values('"+number+"','"+classname+"','"+search_bookname(classname, number)+"','"+dateoff+"');";    //要执行的SQL
            
            PreparedStatement stmts = conn.prepareStatement(sql);
            stmts.executeUpdate();  
            
            stmts.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }
    
    //还书更新书籍数据库信息
    public static void returnBook_Update(String classname,String number,String user,String dateoff) {
    	try{
    		connect_mysql();

            String sql = "update "+classname+"Book set state = 'in' where number = '"+number+"';\n";    //要执行的SQL
            PreparedStatement stmts_state = conn.prepareStatement(sql);
            stmts_state.executeUpdate();  
            stmts_state.close();
            
            sql = "update "+classname+"Book set current = 'null' where number = '"+number+"';\n";
            PreparedStatement stmts_current = conn.prepareStatement(sql);
            stmts_current.executeUpdate();  
            stmts_current.close();
            
            sql = "update "+classname+"Book set dateoff = 'null' where number = '"+number+"';\n";
            PreparedStatement stmts_dateoff = conn.prepareStatement(sql);
            stmts_dateoff.executeUpdate();
            stmts_dateoff.close();
            
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }
    //还书更新用户的数据库信息
    public static void returnBook_Delete(String number,String user) {
    	try{
    		connect_mysql();

            String sql = "delete from "+user+"Customer where number = '"+number+"';";  //要执行的SQL
            
            PreparedStatement stmts = conn.prepareStatement(sql);
            stmts.executeUpdate();  
            
            stmts.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }
    //续借更新两者数据库信息
    public static void prolongBook_Update(String classname,String number,String dateoff,String user) {
    	try{
    		connect_mysql();

            String sql = "update "+classname+"Book set dateoff = '"+dateoff+"' where number = '"+number+"';\n";    //要执行的SQL
            PreparedStatement stmts_state = conn.prepareStatement(sql);
            stmts_state.executeUpdate();  
            stmts_state.close();
            
            sql = "update "+user+"Customer set dateoff = '"+dateoff+"' where number = '"+number+"';\n";
            PreparedStatement stmts_current = conn.prepareStatement(sql);
            stmts_current.executeUpdate();  
            stmts_current.close();
            
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }
    
  //查询个人图书信息
    public static void search_personal(String user) {
    	Information.bookarray.clear();
    	try{
    		
    		connect_mysql();

            String sql = "select * from "+user+"Customer;";    //要执行的SQL
            ResultSet rs = stmt.executeQuery(sql);//创建数据对象
                while (rs.next()){
                	Book book = new Book();
                    book.number = rs.getString(1);
                    book.classname = rs.getString(2);
                    book.name = rs.getString(3);
                    book.dateoff = rs.getString(4);
                    Information.bookarray.add(book);
                }
                rs.close();
                stmt.close();
                conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }
    @SuppressWarnings("unchecked")
	
	//是否存在该Table表
    public static boolean isExist_Table(String table) {
    	try{
    		connect_mysql();

            String sql = "show tables";    //要执行的SQL
            ResultSet rs = stmt.executeQuery(sql);//创建数据对象
                while (rs.next()){
                    if(table.equals(rs.getString(1))) {
                    	return true;
                    }
                }
                rs.close();
                stmt.close();
                conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
		return false;
    }
	//查找书名
    public static String search_bookname(String classname,String number) {
    	try{
    		connect_mysql();

            String sql = "select * from "+classname+"book where number='"+number+"';";    //要执行的SQL
            ResultSet rs = stmt.executeQuery(sql);//创建数据对象
            while (rs.next()){
                return rs.getString(3);
            }
            rs.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    	return "null";
    }
    
	//查找书籍状态
    public static String search_bookstate(String classname,String number) {
    	try{
    		connect_mysql();

            String sql = "select * from "+classname+"book where number='"+number+"';";    //要执行的SQL
            ResultSet rs = stmt.executeQuery(sql);//创建数据对象
            while (rs.next()){
                return rs.getString(6);
            }
            rs.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    	return "null";
    }
    
	//查找书籍还书日期
    public static int search_bookdateoff(String classname,String number) {
    	try{
    		connect_mysql();

            String sql = "select * from "+classname+"book where number='"+number+"';";    //要执行的SQL
            ResultSet rs = stmt.executeQuery(sql);//创建数据对象
            while (rs.next()){
                return Integer.parseInt(rs.getString(10));
            }
            rs.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    	return 0;
    }

    //查找图书馆状态
    public static String search_librarystate(String ID) {
        try{
            connect_mysql();

            String sql = "select * from Library where ID='"+ID+"';";    //要执行的SQL
            ResultSet rs = stmt.executeQuery(sql);//创建数据对象
            while (rs.next()){
                return 'in';
            }
            rs.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
        return "null";
    }
}

    //插入新图书馆
    public static void insertLibrary(String ID,String Name,String Address) {
        try{
            connect_mysql();

            String sql = "insert into "+"Library"+" values('"+ID+"','"+Name+"','"+Address+"');";    //要执行的SQL
            
            PreparedStatement stmts = conn.prepareStatement(sql);
            stmts.executeUpdate();  
            
            stmts.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }

    //查询图书馆
     public static void selectLibrary() {
        Information.bookarray.clear();
        try{
            
            connect_mysql();

            String sql = "select * from Library;";    //要执行的SQL
            ResultSet rs = stmt.executeQuery(sql);//创建数据对象
                while (rs.next()){
                    Library library = new Library();
                    Library.ID = rs.getString(1);
                    Library.Name = rs.getString(2);
                    Library.Address = rs.getString(3);
                }
                rs.close();
                stmt.close();
                conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }

    //删除图书馆
    public static void deleteLibrary(String ID) {
        try{
            connect_mysql();
            String sql = "delete from "+"Library where ID = '"+ID+"';";  //要执行的SQL
            
            PreparedStatement stmts = conn.prepareStatement(sql);
            stmts.executeUpdate();  
            
            stmts.close();
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }

    //更改图书馆
    public static void updateLibrary(String ID,String Name,String Address) {
        try{
            connect_mysql();

            String sql = "update "+"Library set Name = '"+Name+"' where ID = '"+ID+"';\n";    //要执行的SQL
            PreparedStatement stmts_Name = conn.prepareStatement(sql);
            stmts_Name.executeUpdate();  
            stmts_Name.close();
            
            sql = "update "+"Library set Address = '"+Address+"' where ID = '"+ID+"';\n";
            PreparedStatement stmts_Address = conn.prepareStatement(sql);
            stmts_Address.executeUpdate();  
            stmts_Address.close();
            
            
            stmt.close();
            conn.close();
            }catch(Exception e)
            {
                e.printStackTrace();
            }
    }
    
