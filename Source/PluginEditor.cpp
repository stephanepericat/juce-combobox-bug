/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ComboboxBugAudioProcessorEditor::ComboboxBugAudioProcessorEditor (ComboboxBugAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    selector.addItemList(audioProcessor.choices, 1);
    selector.setSelectedId(1);
    selector.onChange = [&]() {
        std::cout << "selected: " << selector.getSelectedItemIndex() << std::endl;
    };
    addAndMakeVisible(selector);
    
    selectorAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(audioProcessor.state, "LIST", selector);
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
}

ComboboxBugAudioProcessorEditor::~ComboboxBugAudioProcessorEditor()
{
}

//==============================================================================
void ComboboxBugAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

//    g.setColour (juce::Colours::white);
//    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), juce::Justification::centred, 1);
}

void ComboboxBugAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    selector.setBounds(getWidth() / 2 - 80, getHeight() / 2 - 10, 160, 20);
}
