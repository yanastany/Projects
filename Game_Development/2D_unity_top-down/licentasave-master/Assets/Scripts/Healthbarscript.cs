using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Healthbarscript : MonoBehaviour
{
    // Start is called before the first frame update
    public Slider slider;

    public void SetMaxH(int health)
    {
        slider.maxValue = health;
        slider.value = health;
    }
    public void setHealth(int healt)
    {
        slider.value = healt;
    }
}
