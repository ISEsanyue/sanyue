package com.littleheap.Manager;

import javax.swing.JPanel;
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
import java.awt.Color;

public class deleteLibrary extends JPanel implements ActionListener{
	private JTextField tf_ID;
	private JLabel lb_ID;
	private JButton back;
	private JButton btn_submit;

	/**
	 * Create the panel.
	 */
	public deleteLibrary() {
		setBackground(Color.PINK);
		setLayout(null);
		
		JLabel label = new JLabel("\u65B0\u4E66\u5F55\u5165");
		label.setHorizontalAlignment(SwingConstants.CENTER);
		label.setFont(new Font("宋体", Font.BOLD, 40));
		label.setBounds(530, 0, 294, 105);
		add(label);
		
		lb_ID = new JLabel("\u7F16\u53F7\uFF1A");
		lb_ID.setFont(new Font("宋体", Font.BOLD, 35));
		lb_ID.setBounds(293, 137, 194, 55);
		add(lb_ID);
		
		tf_ID = new JTextField();
		tf_ID.setFont(new Font("宋体", Font.BOLD, 35));
		tf_ID.setColumns(10);
		tf_ID.setBounds(486, 127, 526, 75);
		add(tf_ID);
		
		btn_submit = new JButton("\u63D0\u4EA4");
		btn_submit.setFont(new Font("宋体", Font.BOLD, 35));
		btn_submit.setBounds(573, 833, 251, 80);
		add(btn_submit);
		btn_submit.addActionListener(this);
		
		back = new JButton("\u8FD4\u56DE");
		back.setFont(new Font("宋体", Font.PLAIN, 26));
		back.setBounds(0, 0, 115, 82);
		add(back);
		back.addActionListener(this);

	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource() == back) {
			//点击返回按钮
			MainInterface.DeleteLibrarytoManager();
		}else if(e.getSource() == btn_submit) {
			//点击提交按钮
			//判定录入信息是否冲突
			String ID = tf_ID.getText();
			
			if(TableOperate.search_librarystate(ID).equals("in")) {
				//插入书籍信息
				TableOperate.deleteLibrary(ID);
				tf_ID.setText("");
				JOptionPane.showMessageDialog(null, "恭喜", "图书馆删除成功", JOptionPane.OK_CANCEL_OPTION);
			}else {
				JOptionPane.showMessageDialog(null, "该图书馆不存在", "图书馆删除失败", JOptionPane.ERROR_MESSAGE);
			}
		}
	}
}