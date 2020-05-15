ΕΠΑΛ ΚΙΣΑΜΟΥ-ΓΕΛ ΚΙΣΑΜΟΥ

Η ηλιακή ενέργεια αποτελεί ανανεώσιμη πηγή ενέργειας με πρόσφορη μέθοδο χρησιμοποίησή της τα φωτοβολταϊκά πάνελ. Όμως ο ήλιος αποδίδει τα μέγιστα μόνο όταν «πέφτει» κάθετα στο πάνελ, έτσι ψάχνουμε τρόπο να ακολουθεί το πάνελ τις ακτίνες του ήλιου. Ένας τρόπος παρακολούθησης του είναι με φωτοευαίσθητες αντιστάσεις οι οποίες παρακολουθούνται από τον μικροελεγκτή arduino και με servo ο μικροελεγκτής προσαρμόζει το πάνελ ώστε οι ακτίνες να πέφτουν κάθετα.
Πιθανά υλικά :

1.arduino uno και mega
2.   4 ldr 
3.  2 servo (link:  https://grobotronics.com/servo-small-5kg.cm-metal-gears-with-analog-feedback-feetech-fs9225m.html  ΚΑΙ https://grobotronics.com/analog-feedback-micro-servo-plastic-gear.html )
4.wires
5..breadboard (link: https://grobotronics.com/adafruit-perma-proto-quarter-sized-breadboard-pcb-single.html )
6.Πλαστικά γρανάζια απο 3D εκτυπωτή του εκφέ χανίων

ΤΕΛΙΚΑ
ΠΕΡΙΓΡΑΦΗ ΠΡΟΒΛΗΜΑΤΟΣ
Η εποχή μας απαιτεί μεγάλα ενεργειακά αποθέματα , έτσι ένα αποδοτικό φωτοβολταικό πάνελ που ακολουθεί τον ήλιο μας δείχνει τον δρόμο στους κατασκευαστές φωτοβ.συστημάτων.Πόσο μάλλον όταν το πρότζεκτ μας καταγράφει online τις γωνίες που δημιουργεί ο ήλιος στο στερέωμα στο καστέλι κισάμου και έτσι δείχνει ανα ημέρα και ώρα την κατάλληλη γωνία που πρέπει να έχει το φ. πάνελ για μέγιστη απόδοση.
Το μοίρασμα της γνώσης προτεραιότητα μας!
Μια επιστημονική εργασία αυτού του είδους εκπαιδεύει τους μελλοντικούς μας επιστήμονες στο διαθεματικό πλαίσιο STEM-ΘΕΤΙΚΕΣ ΕΠΙΣΤΗΜΕΣ-ΡΟΜΠΟΤΙΚΗ.
ΑΚΟΛΟΥΘΩΝΤΑΣ ΤΟ ΜΟΝΟΠΑΤΙ ΤΟΥ ΗΛΙΟΥ
Σε συνέχεια της προηγούμενης απάντησης η ιδέα μας είναι να κατασκευάσουμε ένα ηλιακό ανιχνευτή της πορείας του ήλιου που θα προσαρμόζει το φωτοβολταικό πάνελ μας κάθετα στις ακτίνες του ήλιου για να έχει την μέγιστη απόδοση και ταυτόχρονα θα καταγράφει τις γωνίες αυτές.Θα χρησιμοποιήσουμε 4 ldr φωτοαντιστάσεις-οι αισθητήρες φωτός που ανάλογα με το φως που λαμβάνουν θα δίνουν εντολή να στραφεί το πάνελ μας στη σωστή θέση- 2 σερβομηχανισμούς για να εκτελούν τις παραπάνω εντολές και 2 αισθητήρες κλίσης για την καταγραφή αυτών των γωνιών. Φυσικά και arduino που είναι ο εγκέφαλος της κατασκευής μας.
3D εκτυπωμένα εξαρτήματα θα δώσουν σταθερότητα και αποδοτικότητα στην κατασκευή μας.
Η ομάδα μας αποτελείται απο 3 μαθητές του ΓΕΛ Κισάμου β λυκείου με θαυμαστή όρεξη για μάθηση.
ΑΘΗΝΑ ΑΘΟΥΣΑΚΗ
ΣΤΕΛΛΑ ΑΜΠΟΥΧΑΝΗ
ΣΠΥΡΟΣ ΕΙΡΗΝΑΚΗΣ
Τα κορίτσια είναι οι προγραμματίστριες του arduino και ο Σπύρος το πρακτικό μυαλό.
(Βέβαια οι απαιτήσεις του έργου ήταν να αναμιχθούν όλοι σε όλα τα στάδια της κατασκευής)
Ο Σπύρος βοήθησε και στο 3D σχεδιασμό εξαρτημάτων.
ΒΙΒΛΙΟΓΡΑΦΙΚΕΣ ΑΝΑΦΟΡΕΣ
1) https://en.wikipedia.org/wiki/Sun_path
2)https://en.wikipedia.org/wiki/Position_of_the_Sun
3)https://www.youtube.com/watch?v=lJVEubm9Ja8
4)https://www.instructables.com/id/Arduino-Solar-Tracker/
Ο ΔΕΥΤΕΡΟΣ ΑΙΣΘΗΤΗΡΑΣ ΣΥΝΔΕΜΕΝΟΣ ΣΤΟ MEGA ΧΡΗΣΙΜΟΠΟΙΕΙ ΤΗΝ ΒΙΒΛΙΟΘΗΚΗ:
I2C device class (I2Cdev) demonstration Arduino sketch for MPU9250 class using DMP (MotionApps v2.0)
// 6/21/2012 by Jeff Rowberg <jeff@rowberg.net>
// Updates should (hopefully) always be available at https://github.com/jrowberg/i2cdevlib



