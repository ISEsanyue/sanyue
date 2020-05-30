package com.littleheap.User;

import javax.swing.JPanel;

import com.littleheap.MainInterface;
import com.littleheap.DataBase.TableOperate;
import com.littleheap.Static.Information;

import java.awt.Color;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

public class UserInterface extends JPanel implements ActionListener{
	private JButton back;
	private JLabel label;
	private static JLabel lb_user;
	private JButton btn_return;
	private JButton btn_borrow;
	private JButton btn_prolong;
	private JButton btn_personal;
	private JButton btn_personalin;
	private JButton btn_libraryin;
	/**
	 * Create the panel.
	 */
	public UserInterface() {
		setBackground(new Color(0, 191, 255));
		setLayout(null);
		
		back = new JButton("\u8FD4\u56DE");
		back.setFont(new Font("宋体", Font.PLAIN, 26));
		back.setBounds(0, 0, 115, 82);
		add(back);
		back.addActionListener(this);
		
		label = new JLabel("\u7528\u6237\u754C\u9762");
		label.setHorizontalAlignment(SwingConstants.CENTER);
		label.setFont(new Font("宋体", Font.BOLD, 40));
		label.setBounds(512, 47, 294, 105);
		add(label);
		
		lb_user = new JLabel("New label");
		lb_user.setHorizontalAlignment(SwingConstants.CENTER);
		lb_user.setFont(new Font("宋体", Font.BOLD, 28));
		lb_user.setBounds(944, 0, 356, 56);
		add(lb_user);
		
		btn_borrow = new JButton("\u501F\u4E66");
		btn_borrow.setFont(new Font("宋体", Font.BOLD, 40));
		btn_borrow.setBounds(31, 233, 280, 505);
		add(btn_borrow);
		btn_borrow.addActionListener(this);
		
		btn_return = new JButton("\u8FD8\u4E66");
		btn_return.setFont(new Font("宋体", Font.BOLD, 40));
		btn_return.setBounds(351, 233, 280, 505);
		add(btn_return);
		btn_return.addActionListener(this);
		
		btn_prolong = new JButton("\u7EED\u501F");
		btn_prolong.setFont(new Font("宋体", Font.BOLD, 40));
		btn_prolong.setBounds(674, 233, 280, 505);
		add(btn_prolong);
		btn_prolong.addActionListener(this);
		
		btn_personal = new JButton("\u4E2A\u4EBA\u4FE1\u606F");
		btn_personal.setFont(new Font("宋体", Font.BOLD, 40));
		btn_personal.setBounds(999, 233, 280, 505);
		add(btn_personal);
		btn_personal.addActionListener(this);
		
		btn_personalin = new JButton("\u501f\u9605\u4fe1\u606f");
		btn_personalin.setFont(new Font("宋体", Font.BOLD, 40));
		btn_personalin.setBounds(1200, 100, 280, 505);
		add(btn_personalin);
		btn_personalin.addActionListener(this);

		btn_libraryin = new JButton("\u501f\u9605\u4fe1\u606f");
		btn_libraryin.setFont(new Font("宋体", Font.BOLD, 40));
		btn_libraryin.setBounds(1200, 100, 280, 505);
		add(btn_libraryin);
		btn_libraryin.addActionListener(this);

	}

	public static void setUser() {
		lb_user.setText("当前用户："+Information.user);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource() == back) {
			MainInterface.UsertoMain();
		}else if(e.getSource() == btn_borrow){
			MainInterface.UsertoBorrow();
		}else if(e.getSource() == btn_return) {
			MainInterface.UsertoReturn();
		}else if(e.getSource() == btn_prolong) {
			MainInterface.UsertoProlong();
		}else if(e.getSource() == btn_personalin){
			TableOperate.search_personal(Information.user);
			personalin.setTextArea();
			MainInterface.UsertoPersonalin();
		}
		else if(e.getSource() == btn_personal) {
			TableOperate.search_personal(Information.user);
			PersonalInformation.setTextArea();
			MainInterface.UsertoPersonal();
		}
		else if(e.getSource() == btn_libraryin) {
			libraryin.setTextArea();
			MainInterface.UsertoLibraryin();
		}
	}
}