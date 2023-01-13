Action()
{			
	
	lr_start_transaction("UC7_Sign_Up");
		
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


	
	
	/* Sign_Up */
	

	
	lr_start_transaction("signUpButton");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(104);

	web_url("login.pl", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("signUpButton",LR_AUTO);
	
	
	
	
	lr_start_transaction("profileFill");

	web_submit_data("login.pl_3", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=mam", ENDITEM, 
		"Name=password", "Value=lady", ENDITEM, 
		"Name=passwordConfirm", "Value=lady", ENDITEM, 
		"Name=firstName", "Value=Mam", ENDITEM, 
		"Name=lastName", "Value=Lady", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=register.x", "Value=83", ENDITEM, 
		"Name=register.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("profileFill",LR_AUTO);
	
	

	lr_start_transaction("afterReg");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(23);

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("afterReg",LR_AUTO);
	
	

	lr_start_transaction("signOff");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(42);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("signOff",LR_AUTO);
	
		lr_end_transaction("UC7_Sign_Up",LR_AUTO);
	return 0;
}
