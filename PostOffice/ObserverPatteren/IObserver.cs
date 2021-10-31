﻿using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ObserverPatteren
{
    // Interface
    // Interfaces gør det muligt at have mange forskellige Subscribers, der alle følge samme struktur.
    public interface IObserver
    {
        public string Name();
        public void AddSubscription(Mail subscription);
        public void RemoveSubscription(Mail subscription);
        public void Update();
    }
}
