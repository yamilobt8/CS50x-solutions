function showMessageForm() {
    document.getElementById("messageForm").style.display = "block";
    document.getElementById("ratingForm").style.display = "none";
}

function showRatingForm() {
    document.getElementById("ratingForm").style.display = "block";
    document.getElementById("messageForm").style.display = "none";
}

function submitMessage() {
    var messageContent = document.getElementById("messageFormContent");
    var message = messageContent.querySelector("textarea").value;

    if (message.trim() !== "") {
        alert("Message submitted:\n\n" + message);
        messageContent.querySelector("textarea").value = "";
        document.getElementById("messageForm").style.display = "none";
    }
}

function submitRating() {
    var ratingValue = document.getElementById("ratingRange").value;

    if (parseInt(ratingValue) > 50) {
        alert("Thank you for your positive rating!");
    } else {
        alert("No need for your rating.");
    }

    document.getElementById("ratingForm").style.display = "none";
}

function submitChoice(button) {
    var row = button.parentNode.parentNode;
    var inputs = row.querySelectorAll("input");

    // Get the input values
    var pset = inputs[0].value;
    var language = inputs[1].value;
    var week = inputs[2].value;

    // Clear the input values
    inputs[0].value = "";
    inputs[1].value = "";
    inputs[2].value = "";
}