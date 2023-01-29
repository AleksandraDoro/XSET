Action()
{
	
	lr_start_transaction("UC2_LoginLogout");
	
	
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
	

/*Correlation comment - Do not change!  Original value='135538.158039692zQHVHttpAAtVzzzHtViDAptztAcf' Name ='userSession' Type ='ResponseBased'*/
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
		
	lr_think_time(5);
	/* Login step */

	lr_start_transaction("login");
	
web_reg_find("Fail=NotFound",
		"Text/IC=Welcome, <b>{login}</b>, to the Web Tours reservation pages.",
		LAST);

	
	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

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
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=67", ENDITEM,
		"Name=login.y", "Value=11", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);

	lr_end_transaction("login",LR_AUTO);

//		lr_think_time(5);
//		
//		/* Logout step */
//	
//	lr_start_transaction("logout");
//	
//	web_reg_find("Fail=NotFound",
//		"Text/IC=Welcome to the Web Tours site.",
//		LAST);
//
//	web_revert_auto_header("Sec-Fetch-User");
//
//	web_url("SignOff Button", 
//		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
//		"TargetFrame=body", 
//		"Resource=0", 
//		"RecContentType=text/html", 
//		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
//		"Snapshot=t3.inf", 
//		"Mode=HTML", 
//		LAST);
//
//	lr_end_transaction("logout",LR_AUTO);

	
		lr_end_transaction("UC2_LoginLogout",LR_AUTO);
	return 0;
}