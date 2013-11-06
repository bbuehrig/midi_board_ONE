/**
 *  @file		setup.h
 *  Project		axefx.de MIDI Borad
 *	@brief		Setup-File for your personal MIDI-Board
 *	@version	1.0.0
 *  @author		Bastian Buehrig
 *	@date		05/11/13
 *  license		GPL axefx.de - 2013
 */

/** Numbers of Buttons of the MIDI-Board. If you change this value, you have to put more/less lines
 *  of the Button-Definitions in the seup-function. */
#define MAX_BUTTONS            8           // Numbers of Buttons of the board


/** MIDI-Channel-Number for sending the MIDI-Messages */
#define MIDI_CHANNEL           1           // MIDI-Channel for sending Commands


/** Sending PC-Message at running the program. This will send a PC for a specific Preset
 *  while starting your MIDI-Board */
#define START_PROGRAM_NO       2           // Start Program-Preset-No at initialization
