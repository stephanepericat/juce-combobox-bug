/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class ComboboxBugAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    ComboboxBugAudioProcessorEditor (ComboboxBugAudioProcessor&);
    ~ComboboxBugAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    juce::ComboBox selector;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> selectorAttachment;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ComboboxBugAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ComboboxBugAudioProcessorEditor)
};
