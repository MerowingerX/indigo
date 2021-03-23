// iOptron simulator for Arduino
//
// Copyright (c) 2018-2021 CloudMakers, s. r. o.
// All rights reserved.
//
// You can use this software under the terms of 'INDIGO Astronomy
// open-source license' (see LICENSE.md).
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHORS 'AS IS' AND ANY EXPRESS
// OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#define VERSION  "2.5"

#include "common.h"

char tz[] =   "+060";
char dst = '0';
char lon[] =  "+061588";
char lat[] =  "+173335";
char date[] = "210101";

char tracking_mode = '0';
char moving_rate = '0';
char tracking_rate[] = "+00.0000";
char guide_rate[] = "5050";
char hemisphere = '1';

void parseCommand() {
  char command[32], buffer[32];
  if (Serial.read() == ':') {
    int length = Serial.readBytesUntil('#', command, sizeof(command));
    command[length] = 0;
    if (strcmp(command, "V") == 0) {
        Serial.write("V1.00#");
    } else if (strcmp(command, "MountInfo") == 0) {
      Serial.write("0060");
    } else if (strcmp(command, "FW1") == 0) {
      Serial.write("2016110120161101#");
    } else if (strcmp(command, "FW2") == 0) {
      Serial.write("2016110120161101#");
    } else if (strncmp(command, "GLS", 3) == 0) {
      Serial.write(lon);
      Serial.write(formatLong(atol(lat) + 90L * 60L * 60L, false, 6));
      Serial.write('0');
      if (parked)
        Serial.write('6');
      else if (slewing)
        Serial.write('2');
      else if (tracking)
        Serial.write('1');
      else if (target_ra == park_ra && target_dec == park_dec)
        Serial.write('7');
      else 
        Serial.write('0');
      Serial.write(tracking_mode);
      Serial.write(moving_rate);
      Serial.write('2');
      Serial.write(hemisphere);
      Serial.write('#');
    } else if (strncmp(command, "GLT", 3) == 0) {
      Serial.write(tz, 4);
      Serial.write(dst);
      Serial.write(date);
      Serial.write(format60(base_time +  millis() / 1000, "%02d%02d%02d"));
      Serial.write('#');
    } else if (strncmp(command, "GEC", 3) == 0) {
      Serial.write(formatLong(current_dec / 10, true, 9));
      Serial.write(formatLong(current_ra / 15, false, 8));
      Serial.write('#');
    } else if (strncmp(command, "AG", 2) == 0) {
      Serial.write(guide_rate);
      Serial.write('#');
    } else if (strncmp(command, "SG", 2) == 0) {
      strcpy(tz, command + 2);
      Serial.write('1');
    } else if (strncmp(command, "SDS", 3) == 0) {
      dst = command[3];
      Serial.write('1');
    } else if (strncmp(command, "SC", 2) == 0) {
      strncpy(date, command + 2, sizeof(date) - 1);
      Serial.write('1');
    } else if (strncmp(command, "SL", 2) == 0) {
      base_time = parse60(command + 2, "%2d%2d%2d") - millis() / 1000;
      Serial.write('1');
    } else if (strncmp(command, "Sg", 2) == 0) {
      strncpy(lon, command + 2, sizeof(lon) - 1);
      Serial.write('1');
    } else if (strncmp(command, "St", 2) == 0) {
      strncpy(lat, command + 2, sizeof(lat) - 1);
      Serial.write('1');
    } else if (strncmp(command, "SHE", 3) == 0) {
      hemisphere = command[3];
      Serial.write('1');
    } else if (strncmp(command, "RG", 2) == 0) {
      strncpy(guide_rate, command + 2, sizeof(guide_rate) - 1);
      Serial.write('1');
    } else if (strncmp(command, "MS", 2) == 0) {
      slewing = true;
      Serial.write('1');
    } else if (strncmp(command, "Q", 1) == 0) {
      slewing = false;
      ra_rate = 0;
      dec_rate = 0;
      Serial.write('1');
    } else if (strncmp(command, "ST", 2) == 0) {
      tracking = command[2] == '1';
      Serial.write('1');
    } else if (strncmp(command, "RT", 2) == 0) {
      tracking_mode = command[2];
      Serial.write('1');
    } else if (strncmp(command, "MP0", 3) == 0) {
      parked = false;
      Serial.write('1');
    } else if (strncmp(command, "MP1", 3) == 0) {
      parking = true;
      slewing = true;
      Serial.write('1');
    } else if (strncmp(command, "MH", 2) == 0) {
      slewing = true;
      tracking = false;
      target_ra = park_ra;
      target_dec = park_dec;
      Serial.write('1');
    } else if (strncmp(command, "MSH", 2) == 0) {
      slewing = true;
      tracking = false;
      target_ra = park_ra;
      target_dec = park_dec;
      Serial.write('1');
    } else if (strncmp(command, "SR", 2) == 0) {
      moving_rate = command[2];
      Serial.write('1');
    } else if (strncmp(command, "RR", 2) == 0) {
      strncpy(tracking_rate, command + 2, sizeof(tracking_rate) - 1);
      Serial.write('1');
    } else if (strncmp(command, "RD", 2) == 0) {
      Serial.write(tracking_rate);
      Serial.write('#');
    } else if (strncmp(command, "mn", 2) == 0) {
      dec_rate = rates[moving_rate - '1'];
    } else if (strncmp(command, "ms", 2) == 0) {
      dec_rate = -rates[moving_rate - '1'];
    } else if (strncmp(command, "me", 2) == 0) {
      ra_rate = rates[moving_rate - '1'];
    } else if (strncmp(command, "mw", 2) == 0) {
      ra_rate = -rates[moving_rate - '1'];
    } else if (strncmp(command, "qR", 2) == 0) {
      ra_rate = 0;
    } else if (strncmp(command, "qD", 2) == 0) {
      dec_rate = 0;
    } else if (strncmp(command, "q", 1) == 0) {
      ra_rate = 0;
      dec_rate = 0;
    } else if (strncmp(command, "CM", 2) == 0) {
      current_ra = target_ra;
      current_dec = target_dec;
      Serial.write('1');
    } else if (strncmp(command, "Sr", 2) == 0) {
      target_ra = parseLong(command + 2, 8) * 15;
      Serial.write('1');
    } else if (strncmp(command, "Sd", 2) == 0) {
      target_dec = parseLong(command + 2, 9) * 10;
      Serial.write('1');
    }
  }
}