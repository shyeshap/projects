package il.co.ilrd.generic_iot_infrastructure;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.stream.Collectors;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

/**
 * Servlet implementation class Companies
 */
@WebServlet("/companies")
public class Companies extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private CompaniesCrud crud;

	/**
	 * @see HttpServlet#HttpServlet()
	 */
	public Companies() {
		super();
		try {
			Class.forName("com.mysql.jdbc.Driver");
			crud = new CompaniesCrud("jdbc:mysql://localhost/GenericIOT", "root", "ct,h kvmkhj");
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}

	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {		
		System.out.println("get");
		response.setContentType("application/json");
		PrintWriter out = response.getWriter();
		String jsonStr = null;
		
		// get email from token
		try(BufferedReader reader = request.getReader();){
			jsonStr = reader.lines().collect(Collectors.joining());
			JsonObject registerDetails = new JsonParser().parse(jsonStr).getAsJsonObject();
			CompanyDetails comp = crud.read(registerDetails.get("email").getAsString());
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		out.println(Status.OK.toString());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		System.out.println("post");
		response.setContentType("application/json");
		PrintWriter out = response.getWriter();
		String jsonStr = null;

		try(BufferedReader reader = request.getReader();){
			jsonStr = reader.lines().collect(Collectors.joining());
			JsonObject registerDetails = new JsonParser().parse(jsonStr).getAsJsonObject();
			CompanyDetails comp = CompanyDetails.getCompanyDetails(registerDetails);
			if (comp == null) {
				JsonObject ret = new JsonObject();
				ret.addProperty("msg", "one of the fields is missing");
				out.println(ret);
			} else {
				Status status = crud.create(comp);
				out.println(status.toString());
			}
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
	
	protected void doPut(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		System.out.println("put");
		response.setContentType("application/json");
		PrintWriter out = response.getWriter();
		//check token
		try(BufferedReader reader = request.getReader();){
			String jsonStr = reader.lines().collect(Collectors.joining());
			JsonObject updateDetails = new JsonParser().parse(jsonStr).getAsJsonObject();
			CompanyDetails comp = CompanyDetails.getCompanyDetails(updateDetails);
			Status status = crud.update(comp.getEmail(), comp);
			out.println(status.toString());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	protected void doDelete(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		System.out.println("delete");
		response.setContentType("application/json");
		PrintWriter out = response.getWriter();
		//check token
		try(BufferedReader reader = request.getReader();){

			Status status = crud.delete("itai@itai");
			out.println(status.toString());
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
