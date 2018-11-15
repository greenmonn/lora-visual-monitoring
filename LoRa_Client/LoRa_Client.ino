#include <SD.h>
#include <Wire.h>
#include <SPI.h>
#include <RH_RF95.h>

uint8_t image[] = {
				0xFF, 0xD8, 0xFF, 0xE0, 0x00, 0x10, 0x4A, 0x46, 0x49, 0x46, 0x00, 0x01, 0x01, 0x00, 0x00, 0x48,
				0x00, 0x48, 0x00, 0x00, 0xFF, 0xE1, 0x00, 0x80, 0x45, 0x78, 0x69, 0x66, 0x00, 0x00, 0x4D, 0x4D,
				0x00, 0x2A, 0x00, 0x00, 0x00, 0x08, 0x00, 0x04, 0x01, 0x1A, 0x00, 0x05, 0x00, 0x00, 0x00, 0x01,
				0x00, 0x00, 0x00, 0x3E, 0x01, 0x1B, 0x00, 0x05, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x46,
				0x01, 0x28, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x00, 0x87, 0x69, 0x00, 0x04,
				0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x4E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48,
				0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0xA0, 0x01,
				0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0xA0, 0x02, 0x00, 0x04, 0x00, 0x00,
				0x00, 0x01, 0x00, 0x00, 0x00, 0x46, 0xA0, 0x03, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
				0x00, 0x35, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xED, 0x00, 0x38, 0x50, 0x68, 0x6F, 0x74, 0x6F, 0x73,
				0x68, 0x6F, 0x70, 0x20, 0x33, 0x2E, 0x30, 0x00, 0x38, 0x42, 0x49, 0x4D, 0x04, 0x04, 0x00, 0x00,
				0x00, 0x00, 0x00, 0x00, 0x38, 0x42, 0x49, 0x4D, 0x04, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
				0xD4, 0x1D, 0x8C, 0xD9, 0x8F, 0x00, 0xB2, 0x04, 0xE9, 0x80, 0x09, 0x98, 0xEC, 0xF8, 0x42, 0x7E,
				0xFF, 0xC0, 0x00, 0x11, 0x08, 0x00, 0x35, 0x00, 0x46, 0x03, 0x01, 0x22, 0x00, 0x02, 0x11, 0x01,
				0x03, 0x11, 0x01, 0xFF, 0xC4, 0x00, 0x1F, 0x00, 0x00, 0x01, 0x05, 0x01, 0x01, 0x01, 0x01, 0x01,
				0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
				0x08, 0x09, 0x0A, 0x0B, 0xFF, 0xC4, 0x00, 0xB5, 0x10, 0x00, 0x02, 0x01, 0x03, 0x03, 0x02, 0x04,
				0x03, 0x05, 0x05, 0x04, 0x04, 0x00, 0x00, 0x01, 0x7D, 0x01, 0x02, 0x03, 0x00, 0x04, 0x11, 0x05,
				0x12, 0x21, 0x31, 0x41, 0x06, 0x13, 0x51, 0x61, 0x07, 0x22, 0x71, 0x14, 0x32, 0x81, 0x91, 0xA1,
				0x08, 0x23, 0x42, 0xB1, 0xC1, 0x15, 0x52, 0xD1, 0xF0, 0x24, 0x33, 0x62, 0x72, 0x82, 0x09, 0x0A,
				0x16, 0x17, 0x18, 0x19, 0x1A, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x34, 0x35, 0x36, 0x37, 0x38,
				0x39, 0x3A, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
				0x59, 0x5A, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, 0x6A, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78,
				0x79, 0x7A, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97,
				0x98, 0x99, 0x9A, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xB2, 0xB3, 0xB4, 0xB5,
				0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xD2, 0xD3,
				0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9,
				0xEA, 0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFF, 0xC4, 0x00, 0x1F, 0x01,
				0x00, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
				0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0xFF, 0xC4, 0x00, 0xB5,
				0x11, 0x00, 0x02, 0x01, 0x02, 0x04, 0x04, 0x03, 0x04, 0x07, 0x05, 0x04, 0x04, 0x00, 0x01, 0x02,
				0x77, 0x00, 0x01, 0x02, 0x03, 0x11, 0x04, 0x05, 0x21, 0x31, 0x06, 0x12, 0x41, 0x51, 0x07, 0x61,
				0x71, 0x13, 0x22, 0x32, 0x81, 0x08, 0x14, 0x42, 0x91, 0xA1, 0xB1, 0xC1, 0x09, 0x23, 0x33, 0x52,
				0xF0, 0x15, 0x62, 0x72, 0xD1, 0x0A, 0x16, 0x24, 0x34, 0xE1, 0x25, 0xF1, 0x17, 0x18, 0x19, 0x1A,
				0x26, 0x27, 0x28, 0x29, 0x2A, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x43, 0x44, 0x45, 0x46, 0x47,
				0x48, 0x49, 0x4A, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x63, 0x64, 0x65, 0x66, 0x67,
				0x68, 0x69, 0x6A, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x82, 0x83, 0x84, 0x85, 0x86,
				0x87, 0x88, 0x89, 0x8A, 0x92, 0x93, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0xA2, 0xA3, 0xA4,
				0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xC2,
				0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9,
				0xDA, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7,
				0xF8, 0xF9, 0xFA, 0xFF, 0xDB, 0x00, 0x43, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0x03, 0x02,
				0x02, 0x03, 0x05, 0x03, 0x03, 0x03, 0x05, 0x06, 0x05, 0x05, 0x05, 0x05, 0x06, 0x08, 0x06, 0x06,
				0x06, 0x06, 0x06, 0x08, 0x0A, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0A, 0x0A, 0x0A, 0x0A, 0x0A,
				0x0A, 0x0A, 0x0A, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0F, 0x0F,
				0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0xFF, 0xDB, 0x00, 0x43, 0x01, 0x02, 0x02, 0x02,
				0x04, 0x04, 0x04, 0x07, 0x04, 0x04, 0x07, 0x10, 0x0B, 0x09, 0x0B, 0x10, 0x10, 0x10, 0x10, 0x10};

#define SERIAL_BAUDRATE                        115200
#define LORA_FREQ                               868.0

#define MAX_FRAME_SIZE        RH_RF95_MAX_MESSAGE_LEN
#define MAX_RETRANSMISSION                          7
#define ACK_WAIT_TIME                            3000

#define FTYPE_META                               0x01
#define FTYPE_CELL                               0x02

#define GRID_WIDTH                                 10
#define GRID_HEIGHT                                10


typedef struct {
		uint8_t fype;
		uint8_t img_id;
} hdr_t;


RH_RF95 rf95;
uint8_t buf[MAX_FRAME_SIZE];

/*
bool send_wait_ack(uint8_t *buf, uint8_t len){

	for (int i = 0; i < MAX_RETRANSMISSION; ++i) {
		rf95.send(buf, len);
		rf95.waitPacketSent();

		if (rf95.waitAvailableTimeout(ACK_WAIT_TIME))
		{
			if (rf95.recv(buf, &len))
			{
				Serial.print("rssi: ")
				Serial.println(rf95.lastRssi(), DEC);
				Serial.println((char*)buf);

				return true;
			}
		}
	}
	return false;
}
*/

void setup() {

	Serial.begin(SERIAL_BAUDRATE);

	if (!rf95.init()) {
		Serial.println("init failed");
		exit(0);
	}
	Serial.println("Start LoRa Client");

	rf95.setFrequency(LORA_FREQ);     // Setup ISM frequency
	rf95.setTxPower(13);              // Setup Power,dBm
	rf95.setSpreadingFactor(7);       // Setup Spreading Factor (6 ~ 12)
	rf95.setSignalBandwidth(125000);  // Setup BandWidth, option: 7800,10400,15600,20800,31200,41700,62500,125000,250000,500000
	// Lower BandWidth for longer distance.
	rf95.setCodingRate4(5);           // Setup Coding Rate:5(4/5),6(4/6),7(4/7),8(4/8)
}

void loop() {

	// send meta data of image
	header.message_type = MTYPE_IMAGE_META;
	header.frame = total_frame;
	len = sizeof(header_t);
	memcpy(buf, header, len);

	while(1){

		Serial.print("Sending to LoRa Server frame #");
		Serial.println(frameCnt);

		// calculate frame index and length /
		idx = frameCnt * unit_data_length;
//		len = (idx + unit_data_length <= image_size? unit_data_length: image_size-idx);
		len = 100;

		// send frame
		Serial.println(toHexString(&image[idx], len).c_str());
		Serial.println(toHexString(&image[idx], len).length());

		rf95.send(&image[idx], len);
		rf95.waitPacketSent();

		// get ACK
		for( i=0; i<MAX_RETRANSMISSION; i++){

			if (rf95.waitAvailableTimeout(ACK_WAIT_TIME))
			{
				// Should be a reply message for us now
				if (rf95.recv(buf, &len))
				{
					Serial.print("got reply: ");
					Serial.println((char*)buf);
					Serial.print("RSSI: ");
					Serial.println(rf95.lastRssi(), DEC);
				}
				break;
			}
		}
		break;
	}
}