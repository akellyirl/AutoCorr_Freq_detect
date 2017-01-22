# AutoCorr_Freq_detect
An Arduino example of Autocorrelation for the detection of signal frequency

Accurate Frequency Detection is important for many projects such as Guitar/Piano Tuners, Vibration Analyzers, Heartrate Monitors, MEMs Sensor Analysis and Laboratory Instruments.
There have been many fine examples of projects that try to solve this problem but they all use Time Domain techniques; analyzing the signal for features such as : Zero-Crossings, Peak Detection, Slope Detection etc..
 

A Piano playing Middle-C (C4) looks very different from a Synthesizer Playing Middle-C (C4). Any good Time Domain algorithm will work well with the Piano waveform. But the Synthesizer waveform will not be identifiable that way because its very strong harmonic content makes the fundamental frequency undiscernable . It looks impossible to Identify the Frequency of this signal.

It is possible.

Using Autocorrelation it was measured to be 259.91Hz ... only 0.09Hz away from an Exact Middle C Frequency of 260Hz.

See more here: http://www.akellyirl.com/reliable-frequency-detection-using-dsp-techniques/
