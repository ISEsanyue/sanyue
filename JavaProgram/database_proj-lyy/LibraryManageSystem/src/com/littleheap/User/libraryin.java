package com.littleheap.User;

import javax.swing.JPanel;
import java.awt.Color;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JLabel;
import javax.swing.SwingConstants;

import com.littleheap.MainInterface;
import com.littleheap.DataBase.TableOperate;
import com.littleheap.Static.Information;

import javax.swing.JTextArea;

public class libraryin extends JPanel implements ActionListener{
	private JButton back;
	private static JTextArea textArea;
	private JLabel label;
	private static String info;

	/**
	 * Create the panel.
	 */
	public libraryin() {
		setBackground(new Color(127, 255, 212));
		setLayout(null);
		
		back = new JButton("\u8FD4\u56DE");
		back.setFont(new Font("宋体", Font.PLAIN, 26));
		back.setBounds(0, 0, 115, 82);
		add(back);
		back.addActionListener(this);
		
		label = new JLabel("\u4E2A\u4EBA");
		label.setHorizontalAlignment(SwingConstants.CENTER);
		label.setFont(new Font("宋体", Font.BOLD, 40));
		label.setBounds(530, 20, 294, 105);
		add(label);
		
		textArea = new JTextArea();
		textArea.setFont(new Font("Monospaced", Font.PLAIN, 20));
		textArea.setEditable(false);
		textArea.setBounds(111, 125, 1050, 782);
		add(textArea);
		
		info = "馆号                    馆名                    地址\n";

	}

	public static void setTextArea() {
		info = "馆号                    馆名                    地址\n";
		
		for(int i=0;i<Information.libraryarray.size();i++) {
			info = info+"  "+Information.libraryarray.get(i).ID+"                 ";
			info = info+Information.libraryarray.get(i).Name;
            info = info+"      "+Information.libraryarray.get(i).Address+"        ";
		}
		textArea.setText(info);
	}
	
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource() == back) {
			MainInterface.libraryintoUser();
		}
	}
}