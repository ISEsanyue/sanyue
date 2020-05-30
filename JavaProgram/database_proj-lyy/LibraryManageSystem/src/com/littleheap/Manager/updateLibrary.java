package com.littleheap.Manager;

import javax.swing.JPanel;
import java.awt.Color;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.SwingConstants;

import com.littleheap.MainInterface;
import com.littleheap.DataBase.TableOperate;

import javax.swing.JTextField;
import javax.swing.JButton;

public class updateLibrary extends JPanel implements ActionListener {
	private JTextField tf_old_ID;
	private JTextField tf_new_ID;
	private JLabel update;
	private JTextField tf_new_Name;
	private JTextField tf_new_Address;
	private JLabel lb_old_ID;
	private JLabel label;
	private JLabel lb_new_Address;
	private JLabel lb_new_Name;
	private JButton btn_submit;
	private JButton back;

	/**
	 * Create the panel.
	 */
	public updateLibrary() {
		setBackground(new Color(230, 230, 250));
		setLayout(null);
		
		label = new JLabel("\u66F4\u65B0\u56FE\u4E66\u4FE1\u606F");
		label.setHorizontalAlignment(SwingConstants.CENTER);
		label.setFont(new Font("宋体", Font.BOLD, 40));
		label.setBounds(530, 20, 294, 105);
		add(label);
		
		lb_old_ID = new JLabel("\u65E7\u7F16\u53F7\uFF1A");
		lb_old_ID.setFont(new Font("宋体", Font.BOLD, 35));
		lb_old_ID.setBounds(165, 127, 194, 55);
		add(lb_old_ID);
		
		tf_old_ID = new JTextField();
		tf_old_ID.setFont(new Font("宋体", Font.BOLD, 35));
		tf_old_ID.setColumns(10);
		tf_old_ID.setBounds(298, 117, 252, 75);
		add(tf_old_ID);
		
		tf_new_ID = new JTextField();
		tf_new_ID.setFont(new Font("宋体", Font.BOLD, 35));
		tf_new_ID.setColumns(10);
		tf_new_ID.setBounds(507, 274, 526, 75);
		add(tf_new_ID);
		
		update = new JLabel("\u66F4\u65B0\u4FE1\u606F");
		update.setFont(new Font("宋体", Font.BOLD, 35));
		update.setBounds(607, 213, 157, 55);
		add(update);
		
		tf_new_Name = new JTextField();
		tf_new_Name.setFont(new Font("宋体", Font.BOLD, 35));
		tf_new_Name.setColumns(10);
		tf_new_Name.setBounds(507, 466, 526, 75);
		add(tf_new_Name);
		
		tf_new_Address = new JTextField();
		tf_new_Address.setFont(new Font("宋体", Font.BOLD, 35));
		tf_new_Address.setColumns(10);
		tf_new_Address.setBounds(507, 562, 526, 75);
		add(tf_new_Address);
		
		
		lb_new_ID = new JLabel("\u65B0\u7F16\u53F7\uFF1A");
		lb_new_ID.setFont(new Font("宋体", Font.BOLD, 35));
		lb_new_ID.setBounds(285, 284, 194, 55);
		add(lb_new_ID);
		
		lb_new_Name = new JLabel("\u65B0\u4E66\u540D\uFF1A");
		lb_new_Name.setFont(new Font("宋体", Font.BOLD, 35));
		lb_new_Name.setBounds(285, 476, 194, 55);
		add(lb_new_Name);
		
		lb_new_Address = new JLabel("\u65B0\u5206\u7C7B\u540D\u79F0\uFF1A");
		lb_new_Address.setFont(new Font("宋体", Font.BOLD, 35));
		lb_new_Address.setBounds(285, 572, 227, 55);
		add(lb_new_Address);
		
		back = new JButton("\u8FD4\u56DE");
		back.setFont(new Font("宋体", Font.PLAIN, 26));
		back.setBounds(0, 0, 115, 82);
		add(back);
		back.addActionListener(this);
		
		btn_submit = new JButton("\u63D0\u4EA4");
		btn_submit.setFont(new Font("宋体", Font.BOLD, 35));
		btn_submit.setBounds(570, 850, 251, 80);
		add(btn_submit);
		btn_submit.addActionListener(this);

	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource() == back) {
			//点击返回按钮
			MainInterface.UpdateLibrarytoManager();
		}else if(e.getSource() == btn_submit) {
			//点击更新信息提交按钮
			//旧信息
			String old_ID = tf_old_ID.getText();
			//新信息
			String ID = tf_new_ID.getText();
			String Name = tf_new_Name.getText();
			String Address = tf_new_Address.getText();
			
			if(!TableOperate.search_librarystate(old_ID).equals("null")) {
				//删除旧书籍信息
				TableOperate.deleteLibrary(old_ID);
				//插入新书籍信息
				TableOperate.insertLibrary(ID, Name, Address);
				tf_old_ID.setText("");
				tf_new_ID.setText("");
				tf_new_Name.setText("");
				tf_new_Address.setText("");
				JOptionPane.showMessageDialog(null, "成功", "更新信息成功", JOptionPane.OK_CANCEL_OPTION);
			}else {
				JOptionPane.showMessageDialog(null, "输入信息有误", "更新信息失败", JOptionPane.ERROR_MESSAGE);
			}
		}
	}
}