#ifndef TEF6658X_H
#define TEF6658X_H



#define MODULE_FM    0x20 //32
#define MODULE_AM    0x21 //31
#define MODULE_AUDIO 0x30 //48
#define MODULE_APPL  0x40  //64


#define	SET_OPERATION_MODE      0x01
#define GET_OPERATION_STATUS    0x80  //128,
#define	SET_REFERENCE_CLK       0x04
#define	CMD_ACTIVATE            0x05
#define GET_ID                  0x82  //130,
#define GET_SIGNAL_STATUS       0x85  //133,
#define GET_QUALITY_DATA        0x81       //129,
#define SET_VOLUME              0x0A  //10,
#define SET_MUTE                0x0B  //11,
/*
TEF665X_Cmd_Set_Input = 0x0C,  //12,
	TEF665X_Cmd_Set_Output_Source = 0x0D,  //13,

	TEF665X_Cmd_Set_Ana_Out = 0x15,  //21,
	TEF665X_Cmd_Set_Dig_IO = 0x16,  //22,
	TEF665X_Cmd_Set_Input_Scaler = 0x17,  //23,
	TEF665X_Cmd_Set_WaveGen = 0x18,  //24

#define	TEF665X_Cmd_Set_GPIO = 0x03,
#define
#define	TEF665X_Cmd_Get_Operation_Status = 0x80, //128,
#define	TEF665X_Cmd_Get_GPIO_Status = 0x81,  //129,
#define	TEF665X_Cmd_Get_Identification = 0x82,  //130,
#define	TEF665X_Cmd_Get_LastWrite = 0x83, //131
*/
#define CMD_TUNE 0x01
#define CMD_MAXIMUM_LENGTH	20


#define TEF6657_REF_CLK		9216000	//reference clock frequency
#define TEF6657_IS_CRYSTAL_CLK	0	//crstal
#define TEF6657_IS_EXT_CLK	1	//external clock input

/*
TEF665x state transition times will fall within the following limits :
	Power-on  -> Boot state : power supply voltage settling + 5 ms.
	Boot state ->   Idle state : 50 ms.
	Idle state  ->  Active state : 100 ms
*/
typedef enum
{
    TuningFunc_Standby      = 0,
	TuningFunc_Preset 	    = 1, /*!< Tune to new program with short mute time */
    TuningFunc_Search       = 2, /*!< Tune to new program and stay muted */
    TuningFunc_AF_Update    = 3, /*!< Tune to alternative frequency, store quality and tune back with inaudible mute */
    TuningFunc_Jump         = 4, /*!< Tune to alternative frequency with short inaudible mute  */
    TuningFunc_Check        = 5, /*!< Tune to alternative frequency and stay muted */
    TuningFunc_End          = 7  /*!< Release the mute of a Search/Check action (frequency is ignored) */
} TunFuncs_t;

typedef enum{
	TEF6657_Power_on,
	TEF6657_Boot_state ,
	TEF6657_Idle_state,
	TEF6657_Wait_Active,
	TEF6657_Active_state,

	TEF6657_Not_Exist,

	TEF6657_Last
}TEF6657_STATE;

enum
{
	RADIO_BOOT_STATE = 0,
	RADIO_IDLE_STATE,
	RADIO_STANBDY_STATE,
	RADIO_FM_STATE,
	RADIO_AM_STATE
};

typedef struct
{
    uint16_t status;
    int16_t level;
    int16_t freq_offset;
    uint8_t if_bandwidth;
    uint16_t modulation;
} am_quality_t;

typedef struct
{
    uint16_t status;
    int16_t  level;
    uint16_t ultra_sonic_noise;
    uint16_t wideband_am_multi_path;
    int16_t  freq_offset;
    uint8_t  if_bandwidth;
    uint16_t modulation;
} fm_quality_t;

typedef struct
{
    bool stereo;
    bool digital_signal;
} signal_status_t;

typedef enum
{
	BAND_OIRT,
	BAND_FM,
	BAND_AM
} RADIO_BAND;

typedef enum
{
	AREA_EUROPE,
	AREA_EAST_EUROPE,
	AREA_USA,
	AREA_ASIA,
	AREA_JAPAN
} RADIO_AREA;

typedef struct
{
	RADIO_BAND		Band;
	uint32_t		FreqFM;
	uint32_t		FreqAM;
	uint32_t		FreqOIRT;
	RADIO_AREA		Area;
	uint8_t			ScanState;
	uint8_t			FM_SignalLevel;
	uint8_t			AM_SignalLevel;
	uint16_t		Timer;
}RADIO_T;

RADIO_T Radio_t;

enum {
	TEF6657_CMD_tune = 0,
	TEF6657_CMD_open = 1,
	TEF6657_CMD_close = 2,
	TEF6657_CMD_am = 3,
	TEF6657_CMD_fm = 4,
	TEF6657_CMD_GETamSTAUS  = 5,
	TEF6657_CMD_GETfmSTAUS  = 6,
	TEF6657_CMD_GEToirtSTAUS
};


















const unsigned char PatchData[] =
{
   0xF0, 0x00, 0x38, 0x16, 0xD0, 0x80, 0x43, 0xB2, 0x38, 0x1D, 0xD0, 0x80, 0xF0, 0x00, 0x70, 0x00, 0xC2, 0xF7, 0xF0, 0x00, 0x38, 0x4E, 0xD0, 0x80,
   0xF0, 0x00, 0x38, 0xF1, 0xD0, 0x80, 0xC4, 0xA2, 0x02, 0x0C, 0x60, 0x04, 0x90, 0x01, 0x39, 0x07, 0xD0, 0x80, 0xF0, 0x00, 0x38, 0xD3, 0xD0, 0x80,
   0xF0, 0x00, 0x39, 0x0E, 0xD2, 0x80, 0xF0, 0x00, 0x39, 0x12, 0xD0, 0x80, 0x40, 0x20, 0x39, 0x1E, 0xD0, 0x80, 0x9E, 0x30, 0x18, 0xF9, 0xD2, 0x80,
   0xF0, 0x00, 0x39, 0x20, 0xD0, 0x80, 0xF0, 0x00, 0x39, 0x23, 0xD0, 0x80, 0xF0, 0x00, 0x39, 0x38, 0xD0, 0x80, 0xF0, 0x00, 0x39, 0x3B, 0xD0, 0x80,
   0x00, 0x43, 0x39, 0x43, 0xD9, 0x80, 0xF0, 0x00, 0x39, 0x46, 0xD0, 0x80, 0xF0, 0x00, 0x39, 0x60, 0xD0, 0x80, 0xF0, 0x00, 0x39, 0x71, 0xD0, 0x80,
   0xF0, 0x00, 0x39, 0x7F, 0xD0, 0x80, 0xF0, 0x00, 0x39, 0x82, 0xD0, 0x80, 0xF0, 0x00, 0x70, 0x00, 0xA0, 0x14, 0xF0, 0x00, 0x70, 0x00, 0xA0, 0xD4,
   0xF0, 0x00, 0x70, 0x00, 0xA0, 0xDB, 0xF0, 0x00, 0x70, 0x00, 0xA1, 0x0C, 0xF0, 0x00, 0x70, 0x00, 0xA1, 0x12, 0xF0, 0x00, 0x70, 0x00, 0xA1, 0x2D,
   0xF0, 0x00, 0x20, 0x31, 0xD0, 0x80, 0x00, 0x7F, 0x60, 0x02, 0xE2, 0x00, 0xF0, 0x00, 0x0E, 0x22, 0x60, 0x0A, 0xF0, 0x00, 0x00, 0xFF, 0x60, 0x03,
   0xF0, 0x00, 0x01, 0x42, 0xD2, 0x80, 0x90, 0x03, 0x40, 0x02, 0xF0, 0x00, 0x90, 0x43, 0x01, 0x70, 0xD1, 0x80, 0xF0, 0x00, 0x01, 0x69, 0xD0, 0x80,
   0x0E, 0x69, 0x60, 0x0A, 0xA1, 0x60, 0x20, 0x23, 0x00, 0x01, 0x60, 0x01, 0xF0, 0x00, 0x70, 0x00, 0xF0, 0x00, 0xC4, 0xCB, 0x70, 0x00, 0xF0, 0x00,
   0xCA, 0x09, 0x30, 0x23, 0xF0, 0x00, 0xC2, 0xCB, 0x70, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x30, 0x23, 0xD0, 0x08, 0x82, 0x00, 0x0D, 0x50, 0x60, 0x08,
   0xF0, 0x00, 0x0D, 0x51, 0x60, 0x09, 0x30, 0x00, 0x21, 0x80, 0x60, 0x01, 0xF0, 0x00, 0x40, 0x32, 0xF0, 0x00, 0x30, 0x11, 0x45, 0xF3, 0xF0, 0x00,
   0x30, 0x92, 0x2D, 0x30, 0x60, 0x04, 0x31, 0x13, 0x2D, 0x40, 0x60, 0x05, 0x31, 0x94, 0x7F, 0xFF, 0x60, 0x06, 0x32, 0x15, 0x0D, 0x61, 0x60, 0x0A,
   0x32, 0x96, 0x0D, 0x6B, 0x60, 0x0B, 0x33, 0x10, 0x0D, 0x50, 0x60, 0x01, 0x33, 0x90, 0x0D, 0x5C, 0x60, 0x02, 0x30, 0x21, 0x0D, 0x63, 0x60, 0x03,
   0x30, 0x31, 0x0D, 0x75, 0x60, 0x0C, 0x30, 0xA2, 0x8D, 0x00, 0x60, 0x01, 0x30, 0xB3, 0x01, 0x73, 0x60, 0x02, 0x30, 0x41, 0x00, 0x25, 0x60, 0x03,
   0x30, 0xC2, 0x40, 0x44, 0xF0, 0x00, 0x31, 0x43, 0x40, 0x35, 0xF0, 0x00, 0x31, 0xC4, 0x64, 0x00, 0x60, 0x06, 0x32, 0x45, 0x1F, 0x40, 0x60, 0x07,
   0x32, 0xC6, 0x70, 0x00, 0xF0, 0x00, 0x33, 0x47, 0x1E, 0xBC, 0x60, 0x0D, 0x33, 0xC0, 0x01, 0x22, 0x60, 0x01, 0x34, 0x40, 0xFD, 0xEE, 0x60, 0x02,
   0x30, 0x51, 0x7B, 0x8F, 0x60, 0x03, 0x30, 0xD2, 0xC4, 0x29, 0x60, 0x04, 0x31, 0x51, 0x1E, 0xC2, 0x60, 0x0E, 0x32, 0x53, 0xFF, 0x0D, 0x60, 0x02,
   0x32, 0xD4, 0x7D, 0x2E, 0x60, 0x03, 0x30, 0x61, 0xC1, 0x9A, 0x60, 0x04, 0x30, 0xE2, 0x70, 0x00, 0xF0, 0x00, 0x31, 0x61, 0x70, 0x00, 0xF0, 0x00,
   0x32, 0x63, 0x70, 0x00, 0xF0, 0x00, 0x32, 0xE4, 0x70, 0x00, 0xD0, 0x08, 0xF0, 0x00, 0x03, 0x70, 0xD2, 0x80, 0xF0, 0x00, 0x70, 0x00, 0xA0, 0x02,
   0xF0, 0x00, 0x70, 0x00, 0xA0, 0x59, 0xF0, 0x00, 0x02, 0x15, 0xD0, 0x80, 0xF0, 0x00, 0x0D, 0x51, 0x60, 0x0F, 0xF0, 0x00, 0x05, 0x17, 0x60, 0x0E,
   0x23, 0xF6, 0x70, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x21, 0x63, 0x41, 0xF5, 0x91, 0x8F, 0x21, 0xF8, 0x40, 0x74, 0xC3, 0xEF, 0x21, 0xE0, 0xF0, 0x00,
   0xC3, 0xA4, 0x33, 0xF7, 0xF0, 0x00, 0xD8, 0x5B, 0x70, 0x00, 0xF0, 0x00, 0x82, 0x18, 0x70, 0x00, 0xF0, 0x00, 0x9F, 0xAF, 0x18, 0x00, 0xF0, 0x00,
   0x9F, 0x0F, 0x31, 0xF8, 0x90, 0x02, 0xF0, 0x00, 0x70, 0x00, 0x90, 0x28, 0xF0, 0x00, 0x70, 0x00, 0xD0, 0x08, 0xF0, 0x00, 0x22, 0x78, 0xF0, 0x00,
   0x16, 0xD3, 0x60, 0x09, 0xA0, 0x7F, 0x35, 0xF0, 0x1E, 0xBC, 0x60, 0x0D, 0xF0, 0x00, 0x0D, 0x61, 0x60, 0x08, 0xF0, 0x00, 0x03, 0xA5, 0xD2, 0x80,
   0xF0, 0x00, 0x1E, 0xC2, 0x60, 0x0D, 0xF0, 0x00, 0x0D, 0x6B, 0x60, 0x08, 0xF0, 0x00, 0x03, 0xA5, 0xD2, 0x80, 0xF0, 0x00, 0x21, 0x00, 0xF0, 0x00,
   0x83, 0x6D, 0x22, 0xF1, 0xF0, 0x00, 0xF0, 0x00, 0x23, 0x77, 0xF0, 0x00, 0x90, 0x41, 0x36, 0x70, 0xF0, 0x00, 0x9E, 0x79, 0x70, 0x00, 0x90, 0x01,
   0xF0, 0x00, 0x32, 0xF1, 0xD0, 0x08, 0x91, 0xC7, 0x33, 0x75, 0xF0, 0x00, 0xF0, 0x00, 0x34, 0x70, 0xE6, 0x00, 0xF0, 0x00, 0x34, 0xF0, 0xE6, 0x00,
   0xF0, 0x00, 0x24, 0x74, 0xF0, 0x00, 0xF0, 0x00, 0x24, 0xF3, 0xF0, 0x00, 0x8C, 0x24, 0x26, 0xF2, 0x40, 0x16, 0x8A, 0x1B, 0x34, 0x74, 0x4F, 0xF5,
   0x82, 0xB7, 0x34, 0xF3, 0xF0, 0x00, 0xF0, 0x00, 0x20, 0x71, 0x90, 0x05, 0x83, 0x04, 0x70, 0x00, 0xF0, 0x00, 0x8E, 0x67, 0x70, 0x00, 0xF0, 0x00,
   0xF0, 0x00, 0x70, 0x00, 0x90, 0x02, 0xF0, 0x00, 0x36, 0xF6, 0xF0, 0x00, 0xF0, 0x00, 0x34, 0xF0, 0x80, 0x06, 0x82, 0xAF, 0x70, 0x00, 0xF0, 0x00,
   0x82, 0x1B, 0x70, 0x00, 0xD0, 0x09, 0x8E, 0x5F, 0x70, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x70, 0x00, 0xD0, 0x09, 0xF0, 0x00, 0x36, 0xF5, 0xF0, 0x00,
   0xF0, 0x00, 0x34, 0x70, 0xF0, 0x00, 0x40, 0x11, 0x27, 0x72, 0xA1, 0x03, 0x90, 0x8A, 0x20, 0xF3, 0xA1, 0x02, 0x8E, 0xD7, 0x37, 0x72, 0xF0, 0x00,
   0xF0, 0x00, 0x37, 0xF1, 0xE6, 0x00, 0xF0, 0x00, 0x70, 0x00, 0xD0, 0x08, 0xF0, 0x00, 0x22, 0x7A, 0xF0, 0x00, 0x16, 0xC3, 0x60, 0x09, 0xA0, 0x58,
   0xF0, 0x00, 0x18, 0x20, 0xF0, 0x00, 0xF0, 0x00, 0x35, 0x70, 0xF0, 0x00, 0xF0, 0x00, 0x32, 0x7A, 0xD0, 0x08, 0x82, 0x00, 0x0D, 0x51, 0x60, 0x08,
   0x40, 0x03, 0x70, 0x00, 0xF0, 0x00, 0x33, 0x80, 0x70, 0x00, 0xF0, 0x00, 0x21, 0x06, 0x70, 0x00, 0xF0, 0x00, 0x37, 0x00, 0x70, 0x00, 0xF0, 0x00,
   0x37, 0x80, 0x40, 0x15, 0xF0, 0x00, 0x36, 0x83, 0x70, 0x00, 0xF0, 0x00, 0x33, 0x05, 0x0D, 0x61, 0x60, 0x09, 0x32, 0x86, 0x0D, 0x6B, 0x60, 0x0A,
   0x32, 0x10, 0x70, 0x00, 0xF0, 0x00, 0x32, 0x90, 0x70, 0x00, 0xF0, 0x00, 0x33, 0x10, 0x70, 0x00, 0xF0, 0x00, 0x33, 0x90, 0x70, 0x00, 0xF0, 0x00,
   0x34, 0x10, 0x70, 0x00, 0xF0, 0x00, 0x34, 0x90, 0x70, 0x00, 0xF0, 0x00, 0x31, 0x10, 0x70, 0x00, 0xF0, 0x00, 0x31, 0x90, 0x70, 0x00, 0xF0, 0x00,
   0x32, 0x20, 0x70, 0x00, 0xF0, 0x00, 0x32, 0xA0, 0x70, 0x00, 0xF0, 0x00, 0x33, 0x20, 0x70, 0x00, 0xF0, 0x00, 0x33, 0xA0, 0x70, 0x00, 0xF0, 0x00,
   0x34, 0x20, 0x70, 0x00, 0xF0, 0x00, 0x34, 0xA0, 0x70, 0x00, 0xF0, 0x00, 0x31, 0x20, 0x70, 0x00, 0xF0, 0x00, 0x31, 0xA0, 0x70, 0x00, 0xF0, 0x00,
   0x82, 0x00, 0x0D, 0x30, 0x60, 0x0A, 0x0D, 0x40, 0x60, 0x0B, 0xC0, 0x10, 0xF0, 0x00, 0x10, 0x20, 0xF0, 0x00, 0x0D, 0x51, 0x60, 0x0C, 0xC0, 0x10,
   0xF0, 0x00, 0x10, 0x30, 0xF0, 0x00, 0xF0, 0x00, 0x35, 0xC0, 0xD0, 0x08, 0xF0, 0x00, 0x0D, 0x75, 0x60, 0x0F, 0xF0, 0x00, 0x05, 0x63, 0x60, 0x0E,
   0x24, 0xF7, 0x05, 0x1D, 0x60, 0x0D, 0x25, 0x76, 0x70, 0x00, 0xF0, 0x00, 0x91, 0xC7, 0x20, 0xE8, 0x40, 0x15, 0x91, 0x8F, 0x21, 0xE9, 0xD4, 0x09,
   0xC3, 0xEF, 0x20, 0x00, 0x40, 0x12, 0x9F, 0xBE, 0x20, 0x11, 0x58, 0x03, 0xA0, 0x80, 0x35, 0x77, 0x90, 0x01, 0xF0, 0x00, 0x70, 0x00, 0xD0, 0x08,
   0xF0, 0x00, 0x21, 0xF5, 0xF0, 0x00, 0xA0, 0xCA, 0x22, 0x54, 0xF0, 0x00, 0xCC, 0x09, 0x05, 0x17, 0x60, 0x0C, 0x83, 0x2C, 0x70, 0x00, 0xF0, 0x00,
   0x8A, 0x61, 0x70, 0x00, 0xF0, 0x00, 0xAE, 0x48, 0x22, 0x45, 0xA0, 0xCB, 0xA2, 0x28, 0x20, 0x78, 0xF0, 0x00, 0xF0, 0x00, 0x35, 0xF0, 0xF0, 0x00,
   0xF0, 0x00, 0x18, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x30, 0x78, 0xF0, 0x00, 0x16, 0xE3, 0x60, 0x09, 0xA0, 0x27, 0x89, 0x01, 0x23, 0xF4, 0xF0, 0x00,
   0xF0, 0x00, 0x20, 0xF2, 0xF0, 0x00, 0x82, 0x61, 0x21, 0x73, 0xF0, 0x00, 0xA0, 0x50, 0x36, 0x70, 0xF0, 0x00, 0xA0, 0x58, 0x23, 0x72, 0xE1, 0x40,
   0xA8, 0x01, 0x22, 0xF3, 0xF0, 0x00, 0x90, 0x49, 0x22, 0x75, 0xE0, 0x40, 0x80, 0x61, 0x70, 0x00, 0xF0, 0x00, 0x8A, 0x51, 0x33, 0xF1, 0xF0, 0x00,
   0xA0, 0x58, 0x70, 0x00, 0xF0, 0x00, 0xAF, 0x48, 0x70, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x34, 0x70, 0xD0, 0x08, 0x82, 0x00, 0x0D, 0x75, 0x60, 0x08,
   0x90, 0x09, 0x0D, 0x00, 0x60, 0x09, 0xF0, 0x00, 0x35, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x33, 0x80, 0xC0, 0x28, 0xF0, 0x00, 0x10, 0x10, 0xF0, 0x00,
   0xF0, 0x00, 0x34, 0x81, 0xD0, 0x08, 0x82, 0x49, 0x0D, 0x75, 0x60, 0x08, 0xF0, 0x00, 0x70, 0x00, 0x8F, 0xFD, 0x04, 0x00, 0x60, 0x00, 0xA0, 0xB1,
   0x8E, 0xC0, 0x40, 0x00, 0x60, 0x05, 0x60, 0x00, 0x60, 0x05, 0xE6, 0x00, 0xC8, 0x1B, 0x70, 0x00, 0xF0, 0x00, 0xD8, 0xDB, 0x0D, 0x51, 0x60, 0x08,
   0x83, 0x5B, 0x70, 0x00, 0xF0, 0x00, 0x9E, 0xBA, 0x30, 0x03, 0xF0, 0x00, 0xF0, 0x00, 0x30, 0x84, 0xD4, 0x09, 0xF0, 0x00, 0x70, 0x00, 0x8F, 0xAF,
   0xF0, 0x00, 0x0D, 0x75, 0x60, 0x08, 0xF0, 0x00, 0x0D, 0x51, 0x60, 0x09, 0xF0, 0x00, 0x24, 0x03, 0xF0, 0x00, 0xF0, 0x00, 0x27, 0x94, 0xD0, 0x08,
   0xA0, 0x03, 0x70, 0x00, 0xF0, 0x00, 0x00, 0x11, 0x08, 0x00, 0xF0, 0x00, 0x00, 0x11, 0x08, 0x00, 0xC0, 0x0E, 0xA0, 0x09, 0x00, 0x11, 0x08, 0x00,
   0xA0, 0x09, 0x70, 0x00, 0xF0, 0x00, 0xA4, 0x08, 0x70, 0x00, 0xD0, 0x08, 0xA0, 0x03, 0x70, 0x00, 0xF0, 0x00, 0x00, 0x11, 0x08, 0x00, 0xF0, 0x00,
   0x00, 0x11, 0x08, 0x00, 0xC0, 0x26, 0xA0, 0x09, 0x00, 0x11, 0x08, 0x00, 0xA0, 0x09, 0x70, 0x00, 0xF0, 0x00, 0xA4, 0x08, 0x70, 0x00, 0xD0, 0x08,
   0xF0, 0x00, 0x1D, 0x01, 0x60, 0x08, 0xF0, 0x00, 0x0A, 0x2C, 0x60, 0x00, 0xF0, 0x00, 0x01, 0x1A, 0x60, 0x01, 0x31, 0x00, 0x70, 0x00, 0xF0, 0x00,
   0x31, 0x81, 0x70, 0x00, 0xD0, 0x08, 0x10, 0x00, 0x60, 0x03, 0xA0, 0x93, 0x30, 0x23, 0x07, 0x73, 0xD2, 0x80, 0xF0, 0x00, 0x07, 0xC6, 0xD0, 0x80,
   0x40, 0xE0, 0x00, 0x1F, 0x60, 0x01, 0x13, 0xD5, 0x60, 0x07, 0xA0, 0x06, 0x13, 0xFB, 0x60, 0x06, 0xF0, 0x00, 0x90, 0x40, 0x0D, 0x28, 0xD2, 0x80,
   0x14, 0x05, 0x60, 0x06, 0xF0, 0x00, 0xF0, 0x00, 0x0D, 0x28, 0xD2, 0x80, 0x14, 0x0F, 0x60, 0x06, 0xF0, 0x00, 0xF0, 0x00, 0x0D, 0x28, 0xD0, 0x80,
   0xD7, 0xCA, 0x00, 0xFF, 0x60, 0x04, 0x81, 0xD7, 0x0C, 0xF7, 0x60, 0x09, 0xD0, 0x56, 0x70, 0x00, 0xF0, 0x00, 0x82, 0x76, 0x30, 0x17, 0xF0, 0x00,
   0xD0, 0xF6, 0x40, 0x83, 0xF0, 0x00, 0xC1, 0xA4, 0x20, 0x19, 0xF0, 0x00, 0x82, 0xF6, 0x70, 0x00, 0xF0, 0x00, 0xC1, 0x80, 0x20, 0x17, 0xA0, 0x81,
   0xC3, 0xE7, 0x70, 0x00, 0xF0, 0x00, 0xC5, 0xC7, 0x70, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x30, 0x17, 0xD0, 0x08, 0x1E, 0xC8, 0x60, 0x08, 0xA0, 0x7D,
   0xF0, 0x00, 0x20, 0x00, 0xA0, 0x7C, 0x90, 0x00, 0x70, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x70, 0x00, 0xD4, 0x09, 0xF0, 0x00, 0x70, 0x00, 0x8F, 0xD0,
   0x1E, 0xC8, 0x60, 0x08, 0xA0, 0x78, 0xF0, 0x00, 0x30, 0x00, 0xD0, 0x08, 0x00, 0x28, 0x60, 0x00, 0xA0, 0x76, 0x9E, 0x38, 0x0E, 0xF4, 0x60, 0x09,
   0x9E, 0x38, 0x70, 0x00, 0x9F, 0xFF, 0xF0, 0x00, 0x70, 0x00, 0xD0, 0x08, 0x40, 0x40, 0x0C, 0x8A, 0xD5, 0x80, 0xF0, 0x00, 0x0C, 0x8B, 0xD2, 0x80,
   0xF0, 0x00, 0x0F, 0xB1, 0xD2, 0x80, 0x9C, 0x39, 0x70, 0x00, 0xF0, 0x00, 0x9C, 0x31, 0x70, 0x00, 0x90, 0x04, 0xF0, 0x00, 0x70, 0x00, 0x90, 0x03,
   0x40, 0x10, 0x70, 0x00, 0xAF, 0xF3, 0x41, 0xF1, 0x40, 0x40, 0xF0, 0x00, 0xF0, 0x00, 0x10, 0xB1, 0xD0, 0x80, 0x40, 0x00, 0x70, 0x00, 0xAF, 0xF0,
   0x41, 0xF1, 0x40, 0x40, 0xF0, 0x00, 0xF0, 0x00, 0x10, 0xB2, 0xD0, 0x80, 0x40, 0x71, 0x10, 0xB2, 0xD2, 0x80, 0xF0, 0x00, 0x10, 0x81, 0xD0, 0x80,
   0xF0, 0x00, 0x0B, 0xC9, 0x60, 0x08, 0xF0, 0x00, 0x1D, 0x8D, 0xD2, 0x80, 0xF0, 0x00, 0x16, 0xD5, 0xD0, 0x80, 0xF0, 0x00, 0x0B, 0xC9, 0x60, 0x08,
   0xF0, 0x00, 0x1D, 0x8F, 0xD2, 0x80, 0xF0, 0x00, 0x16, 0xDA, 0xD0, 0x80, 0xF0, 0x00, 0x0B, 0x60, 0x60, 0x0E, 0xF0, 0x00, 0x00, 0x04, 0x60, 0x03,
   0xF0, 0x00, 0x3F, 0xFC, 0x60, 0x04, 0x32, 0x63, 0x80, 0x08, 0x60, 0x05, 0x32, 0xE4, 0x19, 0x9A, 0x60, 0x06, 0x33, 0x65, 0x70, 0x00, 0xF0, 0x00,
   0x31, 0xE6, 0x70, 0x00, 0xD0, 0x08, 0x83, 0x6D, 0x0C, 0x35, 0x60, 0x08, 0x40, 0x60, 0x39, 0x36, 0x60, 0x01, 0x41, 0xE2, 0x21, 0x96, 0x60, 0x03,
   0x33, 0x00, 0x41, 0x44, 0xF0, 0x00, 0x33, 0x81, 0x70, 0x00, 0xF0, 0x00, 0x34, 0x02, 0x70, 0x00, 0xF0, 0x00, 0x34, 0x83, 0x70, 0x00, 0xF0, 0x00,
   0x35, 0x04, 0x70, 0x00, 0xF0, 0x00, 0x35, 0x85, 0x70, 0x00, 0xD0, 0x08, 0xF0, 0x00, 0x70, 0x00, 0xAF, 0x54, 0xF0, 0x00, 0x70, 0x00, 0x8F, 0x99,
   0xF0, 0x00, 0x70, 0x00, 0xAF, 0x92, 0xF0, 0x00, 0x0C, 0x51, 0xD2, 0x80, 0xF0, 0x00, 0x21, 0xA0, 0xD0, 0x80, 0xF0, 0x00, 0x05, 0x2E, 0xD2, 0x80,
   0xF0, 0x00, 0x70, 0x00, 0xA0, 0x01, 0xF0, 0x00, 0x21, 0xB7, 0xD0, 0x80, 0xF0, 0x00, 0x20, 0xF0, 0xD2, 0x80, 0x90, 0x02, 0x27, 0xDF, 0xD2, 0x80,
   0x9E, 0x69, 0x70, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x07, 0x00, 0xD1, 0x80, 0xF0, 0x00, 0x23, 0x20, 0xD0, 0x80, 0x17, 0x0B, 0x60, 0x0C, 0xA0, 0x41,
   0x00, 0x40, 0x40, 0x05, 0xF0, 0x00, 0x00, 0x41, 0x24, 0x3F, 0xD0, 0x80, 0xF0, 0x00, 0x70, 0x00, 0xAE, 0xDD, 0xF0, 0x00, 0x0C, 0x8D, 0x60, 0x08,
   0xF0, 0x00, 0x26, 0x0A, 0xD0, 0x80, 0x83, 0xFF, 0x0D, 0x83, 0x60, 0x08, 0xF0, 0x00, 0x01, 0xF4, 0x60, 0x00, 0xF0, 0x00, 0x03, 0xB1, 0x60, 0x01,
   0x10, 0x00, 0x03, 0xB2, 0x60, 0x02, 0x10, 0x01, 0x04, 0x0E, 0x60, 0x00, 0x10, 0x02, 0x04, 0x0F, 0x60, 0x01, 0x10, 0x00, 0x04, 0x5C, 0x60, 0x02,
   0x10, 0x01, 0x04, 0x5D, 0x60, 0x00, 0x10, 0x02, 0x13, 0x80, 0x60, 0x01, 0x10, 0x00, 0x0D, 0x8E, 0x60, 0x09, 0x10, 0x01, 0x02, 0xEE, 0x60, 0x00,
   0x10, 0x07, 0x43, 0x06, 0x60, 0x01, 0x10, 0x10, 0x04, 0x69, 0x60, 0x02, 0x10, 0x11, 0x44, 0x87, 0x60, 0x00, 0x10, 0x12, 0x05, 0xE3, 0x60, 0x01,
   0x10, 0x10, 0x46, 0x08, 0x60, 0x02, 0x10, 0x11, 0x06, 0xAE, 0x60, 0x00, 0x10, 0x12, 0x0D, 0x8C, 0x60, 0x08, 0x10, 0x10, 0x9E, 0x3C, 0x60, 0x00,
   0x10, 0x17, 0x0D, 0x82, 0x60, 0x09, 0x10, 0x00, 0x70, 0x00, 0xF0, 0x00, 0x10, 0x07, 0x70, 0x00, 0xF0, 0x00, 0x10, 0x17, 0x70, 0x00, 0xD0, 0x08,
   0x0D, 0x83, 0x60, 0x08, 0xA0, 0x24, 0xF0, 0x00, 0x00, 0x02, 0xA0, 0x23, 0x90, 0x82, 0x70, 0x00, 0xF0, 0x00, 0x82, 0x8A, 0x70, 0x00, 0x90, 0x03,
   0x90, 0x8A, 0x70, 0x00, 0x90, 0x01, 0xF0, 0x00, 0x70, 0x00, 0x8F, 0xFB, 0x82, 0xBF, 0x70, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x01, 0x99, 0xD2, 0x80,
   0xF0, 0x00, 0x0D, 0x82, 0x60, 0x08, 0xF0, 0x00, 0x26, 0xC1, 0xF0, 0x00, 0xF0, 0x00, 0x00, 0x02, 0xA0, 0x1A, 0x90, 0x82, 0x70, 0x00, 0xF0, 0x00,
   0x82, 0x8A, 0x70, 0x00, 0x90, 0x03, 0x90, 0x8A, 0x70, 0x00, 0x90, 0x01, 0xF0, 0x00, 0x70, 0x00, 0x8F, 0xFB, 0x82, 0x80, 0x70, 0x00, 0xF0, 0x00,
   0xF0, 0x00, 0x70, 0x00, 0xD0, 0x08, 0xF0, 0x00, 0x0D, 0x8E, 0x60, 0x0D, 0xF0, 0x00, 0x3F, 0xFF, 0x60, 0x02, 0xF0, 0x00, 0x00, 0x51, 0xA0, 0x11,
   0xC2, 0x53, 0x70, 0x00, 0xF0, 0x00, 0x8E, 0xC4, 0x70, 0x00, 0x90, 0x01, 0xF0, 0x00, 0x70, 0x00, 0x97, 0xFC, 0xD4, 0x8F, 0x01, 0x99, 0xD2, 0x80,
   0x40, 0x05, 0x0D, 0x8C, 0x60, 0x0D, 0x40, 0x17, 0x3F, 0xFF, 0x60, 0x02, 0x9F, 0x7D, 0x00, 0x51, 0xA0, 0x0A, 0xC2, 0x53, 0x70, 0x00, 0xF0, 0x00,
   0x82, 0xC4, 0x27, 0x1C, 0xD1, 0x80, 0xF0, 0x00, 0x70, 0x00, 0x97, 0xFC, 0x91, 0x46, 0x27, 0x20, 0xD0, 0x80, 0xF0, 0x00, 0x29, 0x15, 0xD2, 0x80,
   0xF0, 0x00, 0x39, 0x86, 0xD2, 0x80, 0xF0, 0x00, 0x28, 0x88, 0xD0, 0x80, 0x01, 0x52, 0x60, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x28, 0xDC, 0xD2, 0x80,
   0xF0, 0x00, 0x28, 0xD5, 0xD0, 0x80, 0xF0, 0x00, 0x70, 0x00, 0xD0, 0x08, 0xF0, 0x00, 0x16, 0xC3, 0x60, 0x08, 0xF0, 0x00, 0x00, 0x9A, 0x60, 0x00,
   0xF0, 0x00, 0x02, 0xE3, 0x60, 0x00, 0x10, 0x00, 0x04, 0xF4, 0x60, 0x00, 0x10, 0x00, 0x06, 0xFF, 0x60, 0x00, 0x10, 0x00, 0x09, 0x07, 0x60, 0x00,
   0x10, 0x00, 0x0B, 0x10, 0x60, 0x00, 0x10, 0x00, 0x0D, 0x1F, 0x60, 0x00, 0x10, 0x00, 0x0F, 0x65, 0x60, 0x00, 0x10, 0x00, 0x0F, 0x65, 0x60, 0x00,
   0x10, 0x00, 0x0D, 0x1F, 0x60, 0x00, 0x10, 0x00, 0x0B, 0x10, 0x60, 0x00, 0x10, 0x00, 0x09, 0x07, 0x60, 0x00, 0x10, 0x00, 0x06, 0xFF, 0x60, 0x00,
   0x10, 0x00, 0x04, 0xF4, 0x60, 0x00, 0x10, 0x00, 0x02, 0xE3, 0x60, 0x00, 0x10, 0x00, 0x00, 0x9A, 0x60, 0x00, 0xF0, 0x00, 0x10, 0x00, 0xF0, 0x00,
   0xF0, 0x00, 0x10, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x16, 0xD3, 0x60, 0x08, 0xF0, 0x00, 0xFF, 0x93, 0x60, 0x00, 0xF0, 0x00, 0xFE, 0x37, 0x60, 0x00,
   0x10, 0x00, 0xFD, 0xD9, 0x60, 0x00, 0x10, 0x00, 0xFE, 0x9F, 0x60, 0x00, 0x10, 0x00, 0x03, 0x85, 0x60, 0x00, 0x10, 0x00, 0x0D, 0x6B, 0x60, 0x00,
   0x10, 0x00, 0x16, 0x84, 0x60, 0x00, 0x10, 0x00, 0x1E, 0x49, 0x60, 0x00, 0x10, 0x00, 0x1E, 0x49, 0x60, 0x00, 0x10, 0x00, 0x16, 0x84, 0x60, 0x00,
   0x10, 0x00, 0x0D, 0x6B, 0x60, 0x00, 0x10, 0x00, 0x03, 0x85, 0x60, 0x00, 0x10, 0x00, 0xFE, 0x9F, 0x60, 0x00, 0x10, 0x00, 0xFD, 0xD9, 0x60, 0x00,
   0x10, 0x00, 0xFE, 0x37, 0x60, 0x00, 0x10, 0x00, 0xFF, 0x93, 0x60, 0x00, 0xF0, 0x00, 0x10, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x10, 0x00, 0xF0, 0x00,
   0xF0, 0x00, 0x16, 0xE3, 0x60, 0x08, 0xF0, 0x00, 0x00, 0x64, 0x60, 0x00, 0xF0, 0x00, 0xFF, 0xA8, 0x60, 0x00, 0x10, 0x00, 0xFF, 0xA6, 0x60, 0x00,
   0x10, 0x00, 0xFF, 0xDF, 0x60, 0x00, 0x10, 0x00, 0x00, 0x01, 0x60, 0x00, 0x10, 0x00, 0x01, 0x28, 0x60, 0x00, 0x10, 0x00, 0x01, 0x2F, 0x60, 0x00,
   0x10, 0x00, 0xFD, 0x23, 0x60, 0x00, 0x10, 0x00, 0xFD, 0xA1, 0x60, 0x00, 0x10, 0x00, 0x03, 0x89, 0x60, 0x00, 0x10, 0x00, 0x02, 0x54, 0x60, 0x00,
   0x10, 0x00, 0xFE, 0x7D, 0x60, 0x00, 0x10, 0x00, 0x00, 0x8C, 0x60, 0x00, 0x10, 0x00, 0xFB, 0xE1, 0x60, 0x00, 0x10, 0x00, 0xF9, 0x42, 0x60, 0x00,
   0x10, 0x00, 0x0C, 0x47, 0x60, 0x00, 0x10, 0x00, 0x0E, 0xA2, 0x60, 0x00, 0x10, 0x00, 0xEC, 0x43, 0x60, 0x00, 0x10, 0x00, 0xEA, 0xCE, 0x60, 0x00,
   0x10, 0x00, 0x17, 0x46, 0x60, 0x00, 0x10, 0x00, 0x17, 0x46, 0x60, 0x00, 0x10, 0x00, 0xEA, 0xCE, 0x60, 0x00, 0x10, 0x00, 0xEC, 0x43, 0x60, 0x00,
   0x10, 0x00, 0x0E, 0xA2, 0x60, 0x00, 0x10, 0x00, 0x0C, 0x47, 0x60, 0x00, 0x10, 0x00, 0xF9, 0x42, 0x60, 0x00, 0x10, 0x00, 0xFB, 0xE1, 0x60, 0x00,
   0x10, 0x00, 0x00, 0x8C, 0x60, 0x00, 0x10, 0x00, 0xFE, 0x7D, 0x60, 0x00, 0x10, 0x00, 0x02, 0x54, 0x60, 0x00, 0x10, 0x00, 0x03, 0x89, 0x60, 0x00,
   0x10, 0x00, 0xFD, 0xA1, 0x60, 0x00, 0x10, 0x00, 0xFD, 0x23, 0x60, 0x00, 0x10, 0x00, 0x01, 0x2F, 0x60, 0x00, 0x10, 0x00, 0x01, 0x28, 0x60, 0x00,
   0x10, 0x00, 0x00, 0x01, 0x60, 0x00, 0x10, 0x00, 0xFF, 0xDF, 0x60, 0x00, 0x10, 0x00, 0xFF, 0xA6, 0x60, 0x00, 0x10, 0x00, 0xFF, 0xA8, 0x60, 0x00,
   0x10, 0x00, 0x00, 0x64, 0x60, 0x00, 0xF0, 0x00, 0x10, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x10, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x17, 0x0B, 0x60, 0x08,
   0xF0, 0x00, 0x00, 0x03, 0x60, 0x00, 0xF0, 0x00, 0x54, 0xC0, 0x60, 0x00, 0x10, 0x00, 0x00, 0x05, 0x60, 0x00, 0x10, 0x00, 0x00, 0x05, 0x60, 0x00,
   0x10, 0x00, 0x00, 0x0F, 0x60, 0x00, 0x10, 0x00, 0x00, 0x0F, 0x60, 0x00, 0x10, 0x00, 0x09, 0xC0, 0x60, 0x00, 0x10, 0x00, 0x0A, 0x20, 0x60, 0x00,
   0x10, 0x00, 0x1D, 0x40, 0x60, 0x00, 0x10, 0x00, 0x1E, 0x60, 0x60, 0x00, 0xF0, 0x00, 0x10, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x10, 0x00, 0xF0, 0x00,
   0xF0, 0x00, 0x70, 0x00, 0xD0, 0x08
};

const unsigned char LutData[] =
{
    /*
   0x40, 0x13, 0x41, 0x68, 0x41, 0xC1, 0x42, 0x14,
   0x47, 0xC5, 0x4D, 0x83, 0x4E, 0x49, 0x4E, 0x53,
   0x4F, 0x92, 0x4F, 0xEA, 0x50, 0x80, 0x56, 0x60,
   0x56, 0xD4, 0x56, 0xD9, 0x61, 0x9F, 0x61, 0xB6,
   0x64, 0x3B, 0x66, 0x09, 0x67, 0x0B, 0x67, 0x1A,
   0x68, 0x87, 0x68, 0xD4
    */
    0x80, 0x17, 0x80, 0x45, 0x80, 0x96, 0x81, 0x5B, 0x82, 0xD6, 0x88, 0x0B, 0x88, 0x10, 0x88, 0xDB, 0x89, 0x48, 0x8B, 0x0A, 0x8B, 0x12, 0x8B, 0x13,
    0x8B, 0x21, 0x8B, 0x26, 0x8C, 0x6F, 0x94, 0xD0, 0x95, 0x20, 0x95, 0x33, 0x95, 0x6F, 0x95, 0xA8, 0x95, 0xAC, 0x95, 0xC3, 0x95, 0xE1, 0x97, 0xC9,
    0x97, 0xF6, 0x98, 0x8D, 0x99, 0x00, 0x9A, 0x00, 0x9E, 0x73, 0xA0, 0x12, 0xA1, 0x03, 0xA2, 0xF0, 0xA3, 0x0D, 0xA3, 0x4C, 0xA3, 0x52, 0xA3, 0xED,
    0xA8, 0x31, 0xAB, 0x01, 0xAB, 0x1F, 0xAB, 0x4C, 0xAC, 0x76, 0xAC, 0x88, 0xAD, 0xB0, 0xAD, 0xB7, 0xB0, 0xE2, 0xB1, 0x01, 0xB1, 0x0B, 0xB1, 0x35,
    0xB1, 0x3B, 0xB1, 0x97, 0xB3, 0x03

};

/*
unsigned char LutByteValues[]=
{
   0x40, 0x13, 0x41, 0x68, 0x41, 0xC1, 0x42, 0x14,
   0x47, 0xC5, 0x4D, 0x83, 0x4E, 0x49, 0x4E, 0x53,
   0x4F, 0x92, 0x4F, 0xEA, 0x50, 0x80, 0x56, 0x60,
   0x56, 0xD4, 0x56, 0xD9, 0x61, 0x9F, 0x61, 0xB6,
   0x64, 0x3B, 0x66, 0x09, 0x67, 0x0B, 0x67, 0x1A,
   0x68, 0x87, 0x68, 0xD4
};
*/


static const u8 ConfData[] = {
//Set the Band related API settings...
11,	0x20,0x0A,0x01,0x00,0x01,0x09,0x38,0x05,0xDC,0x04,0xB0,//FM_BandWidth Auto,  FM_Set_Bandwidth (1, 1, 2360, 1500, 1200)
5,	0x20,0x14,0x01,0x00,0x01,//FM_MphSuppression,   FM_Set_MphSuppression (1, 1)
7,	0x20,0x17,0x01,0x00,0x01,0x04,0xB0,//FM_NoiseBlanker,   FM_Set_NoiseBlanker (1, 1, 1200)

//Set all Weaksignal API settings (LevelOffset)...
//Set the SoftMute API settings...
9,	0x20,0x2A,0x01,0x00,0x03,0x00,0x64,0x00,0xFA,//FM_SmlMode,   FM_Set_SoftMute_Level (1, 3, 100, 250)
11,	0x20,0x28,0x01,0x00,0x3C,0x00,0x78,0x00,0x0A,0x00,0x14,//FM_SmSlowAttack,FM_Set_SoftMute_Time (1, 60, 120, 10, 20)
9,	0x20,0x2C,0x01,0x00,0x03,0x01,0x90,0x03,0xE8,//FM_Smm,FM_Set_SoftMute_Mph (1, 3, 400, 1000)
9,	0x20,0x2B,0x01,0x00,0x03,0x01,0x90,0x03,0xE8,//FM_Smn,FM_Set_SoftMute_Noise (1, 3, 400, 1000)
7,	0x20,0x2D,0x01,0x00,0x01,0x00,0x64,//FM_SmMaximum,FM_Set_SoftMute_Max (1, 1, 100)

//Set the HighCut API settings...
9,	0x20,0x34,0x01,0x00,0x01,0x01,0xF4,0x00,0xC8,//FM_HclMode,FM_Set_HighCut_Level (1, 1, 500, 200)
11,	0x20,0x32,0x01,0x00,0x3C,0x00,0x78,0x00,0x14,0x00,0x14,//FM_HcSlowAttack,FM_Set_HighCut_Time (1, 60, 120, 20, 20)
11,	0x20,0x33,0x01,0x00,0x01,0x01,0x90,0x00,0xC8,0x03,0x20,//FM_Hco,FM_Set_HighCut_Mod (1, 1, 400, 200, 800)
9,	0x20,0x36,0x01,0x00,0x01,0x00,0x64,0x00,0x64,//FM_Hcm,FM_Set_HighCut_Mph (1, 1, 100, 100)
9,	0x20,0x35,0x01,0x00,0x01,0x00,0x64,0x00,0x64,//FM_Hcn,FM_Set_HighCut_Noise (1, 1, 100, 100)
7,	0x20,0x38,0x01,0x00,0x01,0x3A,0x98,//FM_HcMinimum,FM_Set_HighCut_Min (1, 1, 15000)
7,	0x20,0x3A,0x01,0x00,0x01,0x00,0x64,//FM_HcLowCutMinimum,FM_Set_LowCut_Min (1, 1, 100)
7,	0x20,0x37,0x01,0x00,0x01,0x05,0xDC,//FM_HcMaximum,FM_Set_HighCut_Max (1, 1, 1500)

//Set the Stereo API settings...
9,	0x20,0x3E,0x01,0x00,0x01,0x01,0xF4,0x00,0xFA,//FM_StlMode,FM_Set_Stereo_Level (1, 1, 500, 250)
11,	0x20,0x3C,0x01,0x00,0x3C,0x00,0x78,0x00,0x0A,0x00,0x14,//FM_StSlowAttack,FM_Set_Stereo_Time (1, 60, 120, 10, 20)
11,	0x20,0x3D,0x01,0x00,0x01,0x00,0xC8,0x00,0xC8,0x03,0xE8,//FM_Sto,FM_Set_Stereo_Mod (1, 1, 200, 200, 1000)
9,	0x20,0x40,0x01,0x00,0x01,0x00,0x64,0x00,0x64,//FM_Stm,FM_Set_Stereo_Mph (1, 1, 100, 100)
9,	0x20,0x3F,0x01,0x00,0x01,0x00,0x64,0x00,0x64,//FM_Stn,FM_Set_Stereo_Noise (1, 1, 100, 100)

//Set the Audio and Application related API settings...
9,	0x40,0x03,0x01,0x00,0x00,0x00,0x21,0x00,0x03,//AM_GPIO 0 Feature
9,	0x40,0x03,0x01,0x00,0x01,0x00,0x21,0x00,0x00,//AM_GPIO 1 Feature
9,	0x40,0x03,0x01,0x00,0x02,0x00,0x21,0x00,0x00,//AM_GPIO 2 Feature
9,	0x40,0x03,0x01,0x00,0x00,0x00,0x20,0x00,0x03,// FM_GPIO 0 Feature
9,	0x40,0x03,0x01,0x00,0x01,0x00,0x20,0x00,0x00,//FM_GPIO 1 Feature
9,	0x40,0x03,0x01,0x00,0x02,0x00,0x20,0x00,0x00,//FM_GPIO 2 Feature
13,	0x30,0x16,0x01,0x00,0x21,0x00,0x00,0x00,0x20,0x00,0x00,0x11,0x3A,//Dig_IO_IIS_SD_1 Mode
//5,	0x30,0x0B,0x01,0x00,0x00,//Mute
//5,	0x30,0x0A,0x01,0xFF,0xf0,//Volume
7,	0x30,0x0D,0x01,0x00,0x80,0x00,0xE0,//Audio Output Source DAC L/R
};
static int tef6657_patch_load(struct i2c_client *client, const u8 *data, u16 size);
static int tef6657_patch(struct i2c_client *client);
int fm_signal(struct i2c_client *client, fm_quality_t *pfmq);

#endif
