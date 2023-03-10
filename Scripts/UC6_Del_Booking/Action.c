Action()
{
lr_start_transaction("UC6_Del_Booking");

lr_start_transaction("open_site");


	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Not_A Brand\";v=\"99\", \"Google Chrome\";v=\"109\", \"Chromium\";v=\"109\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");
	
				web_reg_find("Fail=NotFound",
		"Text/IC=Welcome to the Web Tours site.",
		LAST);


	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);
	
	lr_end_transaction("open_site",LR_AUTO);

		
					lr_think_time(5);
		
		
	lr_start_transaction("login");
	
				web_reg_find("Fail=NotFound",
				"Text/IC=Welcome, <b>{login}</b>, to the Web Tours reservation pages.",
				LAST);

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");


	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value={login}", ENDITEM, 
		"Name=password", "Value={password}", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);
	
				
			lr_think_time(5);
				

	lr_start_transaction("itinerary");
	

	web_revert_auto_header("Sec-Fetch-User");

	
	web_reg_save_param("flightID",
		"LB/IC=flightID\" value=\"",
		"RB/IC=\"",
		LAST);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_end_transaction("itinerary",LR_AUTO);
	
	
				lr_think_time(5);
				

	lr_start_transaction("delete_booking");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	
	web_reg_find("Fail=Found",
		"Text/IC={flightID}",
		LAST);

	
	web_submit_form("itinerary.pl", 
		"Snapshot=t4.inf", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=removeFlights.x", "Value=77", ENDITEM, 
		"Name=removeFlights.y", "Value=6", ENDITEM, 
		LAST);

	lr_end_transaction("delete_booking",LR_AUTO);
	
	
	
		lr_end_transaction("UC6_Del_Booking",LR_AUTO);

	return 0;
}