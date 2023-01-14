Action()
{
		lr_start_transaction("UC3_ChooseFlight");
		
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
				"\"Not?A_Brand\";v=\"8\", \"Chromium\";v=\"108\", \"Google Chrome\";v=\"108\"");
		
			web_add_auto_header("sec-ch-ua-mobile", 
				"?0");
		
			web_add_auto_header("sec-ch-ua-platform", 
				"\"Windows\"");
			
			web_reg_find("Fail=NotFound",
		"Text/IC=Welcome to the Web Tours site.",
		LAST);

		
		/*Correlation comment - Do not change!  Original value='135531.084487647zQHVDiApVfiDDDDDtVicipciAQf' Name ='userSession' Type ='ResponseBased'*/
			web_reg_save_param_attrib(
				"ParamName=userSession",
				"TagName=input",
				"Extract=value",
				"Name=userSession",
				"Type=hidden",
				SEARCH_FILTERS,
				"IgnoreRedirections=No",
				"RequestUrl=*/nav.pl*",
				LAST);
		
			web_url("welcome.pl", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/WebTours/", 
				"Snapshot=t1.inf", 
				"Mode=HTML", 
				LAST);	
	
	lr_end_transaction("open_site", LR_AUTO);

	
	
	
	/* Buying_ticket */

	
	
	
	lr_start_transaction("login");
	

			web_reg_find("Fail=NotFound",
				"Text/IC=Welcome, <b>{login}</b>, to the Web Tours reservation pages.",
				LAST);
		
			
			web_add_header("Origin", 
				"http://localhost:1080");
		
			web_add_auto_header("Sec-Fetch-User", 
				"?1");
		
			lr_think_time(6);
		
			web_submit_data("login.pl",
				"Action=http://localhost:1080/cgi-bin/login.pl",
				"Method=POST",
				"TargetFrame=body",
				"RecContentType=text/html",
				"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
				"Snapshot=t2.inf",
				"Mode=HTML",
				ITEMDATA,
				"Name=userSession", "Value={userSession}", ENDITEM,
				"Name=username", "Value={login}<", ENDITEM,
				"Name=password", "Value={password}", ENDITEM,
				"Name=login.x", "Value=51", ENDITEM,
				"Name=login.y", "Value=2", ENDITEM,
				"Name=JSFormSubmit", "Value=off", ENDITEM,
				LAST);

	lr_end_transaction("login",LR_AUTO);

	
	
	
	
	
	lr_start_transaction("search_flights_button");
	
			web_revert_auto_header("Sec-Fetch-User");
		
			lr_think_time(45);
		

	web_url("Search Flights Button", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
				"Snapshot=t3.inf", 
				"Mode=HTML", 
				LAST);
		
			web_add_auto_header("Origin", 
				"http://localhost:1080");
		
			web_add_auto_header("Sec-Fetch-User", 
				"?1");
			
lr_end_transaction("search_flights_button",LR_AUTO);
		
			lr_think_time(21);
			
			
			
			
lr_start_transaction("choose_ticket");
		
				web_reg_find("Fail=NotFound",
				"Text/IC=<B>{depart}</B> to <B>{arrive}</B>",
				LAST);
		
			
	web_reg_save_param("outboundFlight",
		"LB/IC=outboundFlight\" value=\"",
		"RB/IC=\"",
		LAST);
			
			
	web_reg_save_param("returnFlight",
		"LB/IC=returnFlight\" value=\"",
		"RB/IC=\"",
		LAST);
			
	

	web_submit_data("reservations.pl",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=depart", "Value={depart}", ENDITEM,
		"Name=departDate", "Value={departDate}", ENDITEM,
		"Name=arrive", "Value={arrive}", ENDITEM,
		"Name=returnDate", "Value={returnDate}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=roundtrip", "Value=on", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=findFlights.x", "Value=63", ENDITEM,
		"Name=findFlights.y", "Value=9", ENDITEM,
		"Name=.cgifields", "Value=roundtrip", ENDITEM,
		"Name=.cgifields", "Value=seatType", ENDITEM,
		"Name=.cgifields", "Value=seatPref", ENDITEM,
		LAST);

	lr_end_transaction("choose_ticket",LR_AUTO);

	lr_think_time(72);

	
	
	
	lr_start_transaction("choose_time_of_flight");
	
			web_reg_find("Fail=NotFound",
				"Text/IC=Total for 1 ticket(s) is = $ ",
				LAST);
		
			web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=returnFlight", "Value={returnFlight}", ENDITEM,
		"Name=numPassengers", "Value=1", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=reserveFlights.x", "Value=74", ENDITEM,
		"Name=reserveFlights.y", "Value=10", ENDITEM,
		LAST);

	lr_end_transaction("choose_time_of_flight",LR_AUTO);

	lr_think_time(45);
	
		lr_start_transaction("logout");
	
				web_reg_find("Fail=NotFound",
		"Text/IC=Welcome to the Web Tours site.",
		LAST);

			web_add_header("Sec-Fetch-User", 
				"?1");
		
			lr_think_time(33);
		
			web_url("SignOff Button", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
				"Snapshot=t10.inf", 
				"Mode=HTML", 
				LAST);

	lr_end_transaction("logout",LR_AUTO);

		lr_end_transaction("UC3_ChooseFlight",LR_AUTO);
	return 0;
}
