package il.co.ilrd.generic_iot_infrastructure.command;

import com.google.gson.JsonObject;

import il.co.ilrd.generic_iot_infrastructure.Response;

public class CRCommand implements Command {
	
	public CRCommand(JsonObject data) {}
	
	@Override
	public Response execute(JsonObject data) {
		return new Response(200, "OK");
	}

}
