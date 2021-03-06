package il.co.ilrd.chat_client;

import java.awt.BorderLayout;
import java.awt.Container;

import javax.swing.JFrame;



public class MainFrame extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = -582593631733082271L;
	MainDetailPanel panel;
	Client client;
	
	public MainFrame(String title, Client client, String name) {
		super(title);
		this.client = client;
	
		// set layout manager
		setLayout(new BorderLayout());
		
		// Create swing component
		panel = new MainDetailPanel(client);
		panel.setBounds(0, 0, 100, 100);
		
		//client.panel = panel;
		// add swing components to content pane
		Container c = getContentPane();
		c.add(panel, BorderLayout.NORTH);
	}

}
	
