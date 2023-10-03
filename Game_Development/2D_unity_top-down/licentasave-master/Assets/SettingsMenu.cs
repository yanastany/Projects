using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Audio;
using UnityEngine.UI;
using TMPro;

public class SettingsMenu : MonoBehaviour
{
    public AudioMixer audioMixer;
    public TMP_Dropdown dropdown;
    Resolution[] resolutions;
    void Start()
    {
        resolutions = Screen.resolutions; 
        dropdown.ClearOptions();
        int curres = 0;
        List<string> o = new List<string>();
        for (int i = 0;i< resolutions.Length; i++)
        {
            string op = resolutions[i].width + " x " + resolutions[i].height;
            o.Add(op);
            if(resolutions[i].width == Screen.currentResolution.width && resolutions[i].height == Screen.currentResolution.height)
            {
                curres = i;
            }
        }
        dropdown.AddOptions(o);
        dropdown.value = curres;
        dropdown.RefreshShownValue();
    }
    public void SetVolume(float volume)
    {
        audioMixer.SetFloat("volume",volume);
       
    }

    public void SetQuality(int i)
    {
        QualitySettings.SetQualityLevel(i);
    }

    public void SetFullScreeen(bool fl)
    {
        Screen.fullScreen = fl;
    }
    
    public void SetRes(int i)
    {
        Resolution r = resolutions[i];
        Screen.SetResolution(r.width,r.height,Screen.fullScreen);
    }
}
