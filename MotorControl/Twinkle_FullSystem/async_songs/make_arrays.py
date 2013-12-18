import numpy as np
import math

all_notes = dict(zip(["a1","a1s","b1","c1","c1s","d1","d1s","e1","f1","f1s","g1","g1s","a2","a2s","b2","c2","c2s","d2","d2s","e2","f2","f2s","g2","g2s","a3","a3s","b3","c3","c3s","d3","d3s","e3","f3","f3s","g3","g3s","a4","a4s","b4","c4","c4s","d4","d4s","e4","f4","f4s","g4","g4s"], \
	list(range(48))))

class String:
	def __init__(self, starting_note, ending_note, tuning):
		self.tuning = tuning
		self.noteRange = range(all_notes[starting_note], all_notes[ending_note]+1)
		self.pitches = [starting_note]
		self.pitchPoses = [self.pos(starting_note)]
		self.pitchTimes = [0]
		self.downTimes = [0]
		self.upTimes = [0]

	def add(self, notes):
		for note in notes:
			pitch = note[0]
			downTime = note[1]
			upTime = note[2]
			if downTime > upTime:
				print "could not add note "+pitch+": downTime > upTime"
			gap = (downTime - self.upTimes[-1])
			print "++++++++++++++"
			print pitch
			print self.pitches[-1]
			time_needed = self.timeFromTo(self.pitches[-1], pitch)
			it_fits =  gap > time_needed
			if it_fits:
				self.pitches.append(pitch)
				self.pitchPoses.append(self.pos(pitch))
				self.pitchTimes.append(downTime - time_needed)
				self.downTimes.append(downTime)
				self.upTimes.append(upTime)
			else:
				print "could not fit the the note "+pitch+" after the note "+self.pitches[-1]
				print "\tneeded "+str(time_needed)+"ms, but gap is "+str(gap)+"ms"

	def pos(self, note):
		return self.tuning[all_notes[note]]

	def timeFromTo(self, note1, note2):
		speed = 20*.001 # small ticks per ms
		return abs(self.pos(note2) - self.pos(note1))/speed

	def bigArray(self):
		return [self.pitchPoses, self.pitchTimes, self.downTimes, self.upTimes]

if __name__ == "__main__":
	String1 = String('g1', 'g2', np.linspace(100, 180, 13))
	String1.add([('g1', 1000, 1100), ('d1', 3000, 3200)])
	print String1.bigArray()
