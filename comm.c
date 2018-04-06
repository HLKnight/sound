#include "comm.h"
#include <stdio.h>
#include <curl/curl.h>
#include <math.h>

/*
	This function takes in RMS values of 1 second, each is calculated by 16000/80 = 200
	samples, but the function will recalculate 8 pieces of RMS values, each
	corresponding to 2000 samples or 125ms of sound.
*/

void sendToServer(double rms[])
{
	double rms8[8], sum;
	int i, j;	// loop counters
	CURL *curl;
	CURLcode res;
	char post[1000];

	for (i=0; i<8; i++)
	{
		sum = 0;
		for(j=0; j<10; j++)
		{
			sum += rms[j+i*10]*rms[j+i*10];
		}
		rms8[i] = sqrt(sum/10);
	}
	// prepare post data
	sprintf(post, "data=%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f;%.2f",
				rms8[0], rms8[1], rms8[2], rms8[3], rms8[4], rms8[5], rms8[6], rms8[7]);
	// send data
	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, URL);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform failed: %s\n", curl_easy_strerror(res));
		curl_easy_cleanup(curl);
	}
	curl_global_cleanup();
}
