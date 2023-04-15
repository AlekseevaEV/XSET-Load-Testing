
open_home_page(){
	
	
	lr_start_transaction("open_home_page");
	
			web_reg_find("Text/IC=To make reservations,please enter your account",
						LAST);
			
			web_add_auto_header("Sec-Fetch-Site", "none");
			web_add_auto_header("Sec-Fetch-Dest", "document");		
			web_add_auto_header("Sec-Fetch-Mode", "navigate");		
			web_add_auto_header("Sec-Fetch-User", "?1");		
			web_add_auto_header("Upgrade-Insecure-Requests", "1");		
			web_add_auto_header("sec-ch-ua", "\"Google Chrome\";v=\"111\", \"Not(A:Brand\";v=\"8\", \"Chromium\";v=\"111\"");		
			web_add_auto_header("sec-ch-ua-mobile", "?0");		
			web_add_auto_header("sec-ch-ua-platform", "\"Windows\"");
		
		/*Correlation comment - Do not change!  Original value='136174.184852167HAAttfQpzDDDDDDDtcAczpHfHi' Name ='userSession' Type ='ResponseBased'*/
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
		
			web_url("WebTours", 
				"URL=http://localhost:1080/WebTours/", 
				"TargetFrame=", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=", 
				"Snapshot=t1.inf", 
				"Mode=HTML", 
				LAST);
		
	lr_end_transaction("open_home_page", LR_AUTO);

	lr_think_time(5);

	return 0;
	
}

login(){

	lr_start_transaction("logIn");
	
			web_reg_find("Text/IC=User password was correct",
					LAST);	

			web_reg_find("Text/IC=Welcome, <b>{login}</b>, to the Web Tours",
					LAST);

			web_reg_find("Fail=Found", "Text/IC=Web Tours Error - Incorrect Password",
					LAST);

			web_add_auto_header("Sec-Fetch-Dest", "frame");		
			web_revert_auto_header("Sec-Fetch-User");		
			web_revert_auto_header("Upgrade-Insecure-Requests");		
			web_add_header("Origin", "http://localhost:1080");
			web_add_auto_header("Sec-Fetch-Site", "same-origin");
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
				"Name=login.x", "Value=78", ENDITEM,
				"Name=login.y", "Value=12", ENDITEM,
				"Name=JSFormSubmit", "Value=off", ENDITEM,
				LAST);


	lr_end_transaction("logIn", LR_AUTO);

	lr_think_time(5);

	return 0;
	
}

click_flights(){

	
	lr_start_transaction("click_flights");
	
			web_reg_find("Text/IC=User has returned to the search page",
				LAST);

			web_find("Text=Flight departing from <B>{departCities}</B> to <B>{arriveCities}</B>",
				LAST);
	
			
			web_add_auto_header("Sec-Fetch-User","?1");		
			web_add_auto_header("Upgrade-Insecure-Requests", "1");		
			web_url("Search Flights Button", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
				"Snapshot=t3.inf", 
				"Mode=HTML", 
				LAST);
	
	lr_end_transaction("click_flights", LR_AUTO);
	
	lr_think_time(5);
	
	return 0;
	
}


select_flight(){

	lr_start_transaction("select_flights");
	
			web_reg_find("Text/IC=Flight Selections",
				LAST);
	
			web_find("Text=Flight departing from <B>{departCities}</B> to <B>{arriveCities}</B>",
				LAST);	

			web_reg_find("Fail=Found", "Text/IC=td align=\"center\">$ 0",
				LAST);

			web_add_header("Origin", "http://localhost:1080");
		
			/*Correlation comment - Do not change!  Original value='262;803;04/10/2023' Name ='outboundFlight' Type ='ResponseBased'*/
			web_reg_save_param_attrib(
				"ParamName=outboundFlight",
				"TagName=input",
				"Extract=value",
				"Name=outboundFlight",
				"Type=radio",
				SEARCH_FILTERS,
				"IgnoreRedirections=No",
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
				"Name=depart", "Value={departCities}", ENDITEM, 
				"Name=departDate", "Value={departDate}", ENDITEM, 
				"Name=arrive", "Value={arriveCities}", ENDITEM, 
				"Name=returnDate", "Value={returnDate}", ENDITEM, 
				"Name=numPassengers", "Value=1", ENDITEM, 
				"Name=seatPref", "Value={seatPref}", ENDITEM, 
				"Name=seatType", "Value={seatType}", ENDITEM, 
				"Name=findFlights.x", "Value=40", ENDITEM, 
				"Name=findFlights.y", "Value=3", ENDITEM, 
				"Name=.cgifields", "Value=roundtrip", ENDITEM, 
				"Name=.cgifields", "Value=seatType", ENDITEM, 
				"Name=.cgifields", "Value=seatPref", ENDITEM, 
				LAST);
			
	lr_end_transaction("select_flights", LR_AUTO);
	
	lr_think_time(5);

	return 0;
	
}
	

sigh_off(){

	lr_start_transaction("sigh_off");
	
			web_reg_find("Text/IC=A Session ID has been created",
				LAST);
	
			web_reg_find("Text/IC=Welcome to the Web Tours site.",
				LAST);

			web_add_header("Sec-Fetch-User", "?1");
			web_add_header("Upgrade-Insecure-Requests", "1");	
			web_url("SignOff Button", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
				"Snapshot=t9.inf", 
				"Mode=HTML", 
				LAST);
			
	lr_end_transaction("sigh_off", LR_AUTO);

	return 0;
	
}


