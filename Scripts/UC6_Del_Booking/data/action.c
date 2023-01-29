Action()
{

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

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("login");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(67);

	web_submit_form("login.pl", 
		"Snapshot=t2.inf", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_start_transaction("itinerary");

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(45);

	web_image("Itinerary Button", 
		"Alt=Itinerary Button", 
		"Snapshot=t3.inf", 
		LAST);

	lr_end_transaction("itinerary",LR_AUTO);

	lr_start_transaction("delete_booking");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(65);

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=210297424-100296-JB", ENDITEM, 
		"Name=flightID", "Value=210297416-177189-JB", ENDITEM, 
		"Name=flightID", "Value=210297416-254112-JB", ENDITEM, 
		"Name=flightID", "Value=210297424-331066-JB", ENDITEM, 
		"Name=flightID", "Value=210297424-407989-JB", ENDITEM, 
		"Name=flightID", "Value=33492785-48-JB", ENDITEM, 
		"Name=flightID", "Value=0-0-P", ENDITEM, 
		"Name=flightID", "Value=0-0-M", ENDITEM, 
		"Name=flightID", "Value=4-0-60", ENDITEM, 
		"Name=flightID", "Value=8-0-60", ENDITEM, 
		"Name=flightID", "Value=1-0-60", ENDITEM, 
		"Name=flightID", "Value=0-0-5\r\n", ENDITEM, 
		"Name=flightID", "Value=6-1-5\r\n", ENDITEM, 
		"Name=flightID", "Value=8-1-5\r\n", ENDITEM, 
		"Name=flightID", "Value=12-1-5\r\n", ENDITEM, 
		"Name=flightID", "Value=15-1-5\r\n", ENDITEM, 
		"Name=flightID", "Value=21-1-5\r\n", ENDITEM, 
		"Name=flightID", "Value=0-1-11", ENDITEM, 
		"Name=flightID", "Value=0-1-11", ENDITEM, 
		"Name=flightID", "Value=0-1-11", ENDITEM, 
		"Name=flightID", "Value=0-1-11", ENDITEM, 
		"Name=flightID", "Value=0-1-11", ENDITEM, 
		"Name=flightID", "Value=0-1-11", ENDITEM, 
		"Name=flightID", "Value=0-1-11", ENDITEM, 
		"Name=flightID", "Value=0-1-11", ENDITEM, 
		"Name=flightID", "Value=0-2-11", ENDITEM, 
		"Name=flightID", "Value=0-2-11", ENDITEM, 
		"Name=flightID", "Value=0-2-11", ENDITEM, 
		"Name=flightID", "Value=0-2-11", ENDITEM, 
		"Name=flightID", "Value=0-2-11", ENDITEM, 
		"Name=flightID", "Value=0-2-11", ENDITEM, 
		"Name=flightID", "Value=0-2-11", ENDITEM, 
		"Name=flightID", "Value=0-25-11", ENDITEM, 
		"Name=removeFlights.x", "Value=77", ENDITEM, 
		"Name=removeFlights.y", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=33", ENDITEM, 
		"Name=.cgifields", "Value=32", ENDITEM, 
		"Name=.cgifields", "Value=21", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=26", ENDITEM, 
		"Name=.cgifields", "Value=17", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=18", ENDITEM, 
		"Name=.cgifields", "Value=30", ENDITEM, 
		"Name=.cgifields", "Value=16", ENDITEM, 
		"Name=.cgifields", "Value=27", ENDITEM, 
		"Name=.cgifields", "Value=25", ENDITEM, 
		"Name=.cgifields", "Value=28", ENDITEM, 
		"Name=.cgifields", "Value=20", ENDITEM, 
		"Name=.cgifields", "Value=14", ENDITEM, 
		"Name=.cgifields", "Value=24", ENDITEM, 
		"Name=.cgifields", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=31", ENDITEM, 
		"Name=.cgifields", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=22", ENDITEM, 
		"Name=.cgifields", "Value=13", ENDITEM, 
		"Name=.cgifields", "Value=23", ENDITEM, 
		"Name=.cgifields", "Value=29", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=12", ENDITEM, 
		"Name=.cgifields", "Value=15", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=19", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		LAST);

	lr_end_transaction("delete_booking",LR_AUTO);

	lr_start_transaction("logout");

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(36);

	web_url("welcome.pl_2", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	return 0;
}